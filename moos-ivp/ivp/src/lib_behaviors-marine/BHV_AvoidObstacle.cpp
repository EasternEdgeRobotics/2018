/*****************************************************************/
/*    NAME: Michael Benjamin, Henrik Schmidt, and John Leonard   */
/*    ORGN: Dept of Mechanical Eng / CSAIL, MIT Cambridge MA     */
/*    FILE: BHV_AvoidObstacle.cpp                                */
/*    DATE: Aug 2nd 2006                                         */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#include <iostream>
#include <cmath> 
#include <cstdlib>
#include "BHV_AvoidObstacle.h"
#include "AOF_AvoidObstacle.h"
#include "OF_Reflector.h"
#include "MBUtils.h"
#include "AngleUtils.h"
#include "GeomUtils.h"
#include "BuildUtils.h"
#include "XYFormatUtilsPoly.h"

using namespace std;

//-----------------------------------------------------------
// Procedure: Constructor

BHV_AvoidObstacle::BHV_AvoidObstacle(IvPDomain gdomain) : 
  IvPBehavior(gdomain)
{
  this->setParam("descriptor", "avoid_obstacles");
  //this->setParam("build_info", "uniform_piece=discrete@course:2,speed:3");
  //this->setParam("build_info", "uniform_grid =discrete@course:9,speed:6");

  m_domain = subDomain(m_domain, "course,speed");

  m_osx               = 0;
  m_osy               = 0;
  m_osh               = 0;
  m_buffer_dist       = 0;
  m_allowable_ttc     = 20;

  m_completed_dist    = 75;
  m_pwt_outer_dist    = 30;
  m_pwt_inner_dist    = 20;

  m_obstacle_relevance = 0;
  
  m_pwt_grade = "linear";

  m_hint_obst_edge_color   = "white";
  m_hint_obst_vertex_color = "dodger_blue";
  m_hint_obst_fill_color   = "gray60";
  m_hint_obst_fill_transparency = 0.7;

  m_hint_buff_edge_color   = "gray60";
  m_hint_buff_vertex_color = "dodger_blue";
  m_hint_buff_fill_color   = "gray70";
  m_hint_buff_fill_transparency = 0.1;

  m_no_alert_request  = false;

  addInfoVars("NAV_X, NAV_Y, NAV_HEADING");
}

//-----------------------------------------------------------
// Procedure: setParam
//     Notes: We expect the "waypoint" entries will be of the form
//            "xposition,yposition".
//            The "radius" parameter indicates what it means to have
//            arrived at the waypoint.

bool BHV_AvoidObstacle::setParam(string param, string val) 
{
  if(IvPBehavior::setParam(param, val))
    return(true);

  double dval = atof(val.c_str());
  bool   non_neg_number = (isNumber(val) && (dval >= 0));
  
  if((param=="polygon") || (param=="points") || (param=="poly")) {
    XYPolygon new_polygon = string2Poly(val);
    if(!new_polygon.is_convex())
      return(false);
    m_obstacle_orig = new_polygon;
    m_obstacle_relevance = 1;
  }
  else if(param == "allowable_ttc")
    return(setNonNegDoubleOnString(m_allowable_ttc, val));
  else if(param == "buffer_dist")
    return(setNonNegDoubleOnString(m_buffer_dist, val));
  else if(param == "obstacle_key")
    return(setNonWhiteVarOnString(m_obstacle_key, val));
  
  else if((param == "pwt_outer_dist") && non_neg_number) {
    m_pwt_outer_dist = dval;
    if(m_pwt_inner_dist > m_pwt_outer_dist)
      m_pwt_inner_dist = m_pwt_outer_dist;
  }  
  else if((param == "pwt_inner_dist") && non_neg_number) {
    m_pwt_inner_dist = dval;
    if(m_pwt_outer_dist < m_pwt_inner_dist)
      m_pwt_outer_dist = m_pwt_inner_dist;
  }  
  else if((param == "completed_dist") && non_neg_number) 
    m_completed_dist = dval;
  else if(param == "no_alert_request")
    return(setBooleanOnString(m_no_alert_request, val));
  else if(param == "visual_hints")
    return(handleVisualHints(val));
  else
    return(false);
  
  return(true);
}


//-----------------------------------------------------------
// Procedure: onSetParamComplete
//   Example: OBSTACLE_UPDATE_REQUEST = "obstacle_key=abe,
//                                       update_var=OBSTACLE_UPDATE_ABE"

void BHV_AvoidObstacle::onSetParamComplete()
{
  if(m_obstacle_key != "") {
    m_obstacle_update_var = "OBSTACLE_UPDATE_" + toupper(m_obstacle_key);
    string msg = "obstacle_key=" + m_obstacle_key;
    msg += ",update_var=" + m_obstacle_update_var;
    postMessage("OBSTACLE_UPDATE_REQUEST", msg);
    addInfoVars(m_obstacle_update_var, "no_warning");
  }
  postConfigStatus();
}

//-----------------------------------------------------------
// Procedure: onHelmStart()

void BHV_AvoidObstacle::onHelmStart()
{
  if(m_no_alert_request || (m_update_var == ""))
    return;

  string s_alert_range = doubleToStringX(m_pwt_outer_dist,1);
  string s_cpa_range   = doubleToStringX(m_completed_dist,1);
  string s_alert_templ = "name=obj_$[OBJNAME] # obstacle_key=$[OBJNAME]";

  string alert_request = "id=obavoid, var=" + m_update_var;
  alert_request += ", val=" + s_alert_templ;
  alert_request += ", alert_range=" + s_alert_range;
  alert_request += ", cpa_range=" + s_cpa_range;

  postMessage("OBJ_ALERT_REQUEST", alert_request);
}

//-----------------------------------------------------------
// Procedure: onIdleState

void BHV_AvoidObstacle::onIdleState()
{
  checkForObstacleUpdate();
  postErasablePolygons();
}

//-----------------------------------------------------------
// Procedure: onCompleteState()

void BHV_AvoidObstacle::onCompleteState() 
{
  postErasablePolygons();
  postRepeatableMessage("OBSTACLE_RESOLVED", m_obstacle_key);
}

//-----------------------------------------------------------
// Procedure: onInactiveState

void BHV_AvoidObstacle::onInactiveState()
{
  //postErasablePolygons();
}

//-----------------------------------------------------------
// Procedure: onIdleToRunState

void BHV_AvoidObstacle::onIdleToRunState()
{
  postConfigStatus();
}

//-----------------------------------------------------------
// Procedure: onRunState

IvPFunction *BHV_AvoidObstacle::onRunState() 
{
  checkForObstacleUpdate();

  // Part 1: Sanity checks
  if(!updatePlatformInfo())
    return(0);  
  if(!m_obstacle_orig.is_convex())
    return(0);
  if(applyBuffer() == false)
    return(0);

  // Part 2: Handle case where behavior is completed 
  double os_dist_to_poly = m_obstacle_orig.dist_to_poly(m_osx, m_osy);
  postMessage("OS_DIST_TO_POLY", os_dist_to_poly);
  if(os_dist_to_poly > m_completed_dist) {
    setComplete();
    return(0);
  }

  if(polyAft(m_osx, m_osy, m_osh, m_obstacle_orig))
    return(0);
  
  // Part 3: Determine the relevance
  m_obstacle_relevance = getRelevance();
  if(m_obstacle_relevance <= 0)
    return(0);
    
  // Part 4: Build/update the underlying objective function and initialize
  AOF_AvoidObstacle  aof_avoid(m_domain);
  aof_avoid.setObstacleOrig(m_obstacle_orig);
  aof_avoid.setObstacleBuff(m_obstacle_buff);
  aof_avoid.setParam("os_x", m_osx);
  aof_avoid.setParam("os_y", m_osy);
  aof_avoid.setParam("os_h", m_osh);
  aof_avoid.setParam("buffer_dist", m_buffer_dist);
  aof_avoid.setParam("allowable_ttc", m_allowable_ttc);

  // Part 5: Initialize the AOF
  bool ok_init = aof_avoid.initialize();
  if(!ok_init) {
    postWMessage("BHV_AvoidObstacles: AOF-Init Error");
    return(0);
  }
  
  // Part 6: Build the actual objective function with reflector
  OF_Reflector reflector(&aof_avoid, 1);
  if(m_build_info != "")
    reflector.create(m_build_info);
  else {
    reflector.setParam("uniform_piece", "discrete@course:3,speed:3");
    reflector.setParam("uniform_grid",  "discrete@course:6,speed:6");
    reflector.create();
  }
  if(!reflector.stateOK()) {
    postWMessage(reflector.getWarnings());
    return(0);
  }

  // Part 7: Extract the objective function, apply priority, post visuals
  IvPFunction *ipf = reflector.extractIvPFunction(true); // true means normalize
  if(ipf) {
    ipf->setPWT(m_obstacle_relevance * m_priority_wt);
    postViewablePolygons();
  }
  
  return(ipf);
}

//-----------------------------------------------------------
// Procedure: getRelevance
//            Calculate the relevance first. If zero-relevance, 
//            we won't bother to create the objective function.

double BHV_AvoidObstacle::getRelevance()
{
  // Part 1: Sanity checks
  if(m_pwt_outer_dist < m_pwt_inner_dist)
    return(0);

  // Part 3: Get the obstacle range and reject if zero
  double obstacle_range = m_obstacle_orig.dist_to_poly(m_osx, m_osy);
  if(obstacle_range == 0)
    return(0);

  // Part 4: Now the easy range cases: when the obstacle is outside 
  //         the min or max priority ranges
  // First declare the range of relevance values to be calc'ed
  double min_dist_relevance = 0;
  double max_dist_relevance = 1;

  if(obstacle_range >= m_pwt_outer_dist)
    return(min_dist_relevance);
  if(obstacle_range <= m_pwt_inner_dist)
    return(max_dist_relevance);

  // Part 5: Handle the in-between case
  // Note: drange should never be zero since either of the above
  // conditionals would be true and the function would have returned.
  double drange = (m_pwt_outer_dist - m_pwt_inner_dist);
  if(drange <= 0)
    return(0);
  double dpct = (m_pwt_outer_dist - obstacle_range) / drange;
  
  // Part 6: Possibly apply the grade scale to the raw distance
  if(m_pwt_grade == "quadratic")
    dpct = dpct * dpct;
  else if(m_pwt_grade == "quasi")
    dpct = pow(dpct, 1.5);

  // Part 7: Now calculate and return the relevance
  double rng_dist_relevance = max_dist_relevance - min_dist_relevance;
  double d_relevance = (dpct * rng_dist_relevance) + min_dist_relevance;

  return(d_relevance);  
}

//-----------------------------------------------------------
// Procedure: checkForObstacleUpdate

bool BHV_AvoidObstacle::checkForObstacleUpdate()
{
  if(m_obstacle_update_var == "") 
    return(true);
      
  double time_since_update = getBufferTimeVal(m_obstacle_update_var);
  if(time_since_update > 0)
    return(false);  

  bool ok;
  string str = getBufferStringVal(m_obstacle_update_var, ok);
  if(!ok)
    return(false);

  // Example: pts={120,-80:120,-50:150,-50:150,-80:138,-80},label=a
  
  bool update_ok = setParam("poly", str);
   
  return(update_ok);
}
  

//-----------------------------------------------------------
// Procedure: handleVisualHints()

bool BHV_AvoidObstacle::handleVisualHints(string hints)
{
  vector<string> svector = parseStringQ(hints, ',');

  for(unsigned int i=0; i<svector.size(); i++) {

    string hint = svector[i];
    string param = tolower(biteStringX(hint, '='));
    string value = hint;
    
    if((param == "obstacle_edge_color") && isColor(value))
      m_hint_obst_edge_color = value;
    else if((param == "obstacle_vertex_color") && isColor(value))
      m_hint_obst_vertex_color = value;
    else if((param == "obstacle_fill_color") && isColor(value))
      m_hint_obst_fill_color = value;
    else if((param == "obstacle_fill_transparency") && isNumber(value)) {
      double transparency = atof(value.c_str());
      transparency = vclip(transparency, 0, 1);
      m_hint_obst_fill_transparency = transparency;
    }
    
    else if((param == "buffer_edge_color") && isColor(value))
      m_hint_buff_edge_color = value;
    else if((param == "buffer_vertex_color") && isColor(value))
      m_hint_buff_vertex_color = value;
    else if((param == "buffer_fill_color") && isColor(value))
      m_hint_buff_fill_color = value;
    else if((param == "buffer_fill_transparency") && isNumber(value)) {
      double transparency = atof(value.c_str());
      transparency = vclip(transparency, 0, 1);
      m_hint_buff_fill_transparency = transparency;
    }
    else
      return(false);
  }
  return(true);
}


//-----------------------------------------------------------
// Procedure: postViewablePolygons

void BHV_AvoidObstacle::postViewablePolygons()
{
  // Part 1 - Render the original obstacle polygon
  if(m_obstacle_orig.is_convex()) {
    m_obstacle_orig.set_active(true);
    m_obstacle_orig.set_color("edge", m_hint_obst_edge_color);
    m_obstacle_orig.set_color("vertex", m_hint_obst_vertex_color);
    
    // If the obstacle is relevant, perhaps draw filled in
    if(m_obstacle_relevance > 0) {
      m_obstacle_orig.set_color("fill", m_hint_obst_fill_color);
      m_obstacle_orig.set_transparency(m_hint_obst_fill_transparency);
    }
    string spec = m_obstacle_orig.get_spec();
    postMessage("VIEW_POLYGON", spec, "orig");
  }
    
  // Part 2 - Render the buffer obstacle polygon
  if(m_obstacle_buff.is_convex() && (m_buffer_dist > 0)) {
    m_obstacle_buff.set_active(true);
    m_obstacle_buff.set_color("edge", m_hint_buff_edge_color);
    m_obstacle_buff.set_color("vertex", m_hint_buff_vertex_color);

    // If the obstacle is relevant, perhaps draw filled in
    if(m_obstacle_relevance > 0) {
      m_obstacle_buff.set_color("fill", m_hint_buff_fill_color);
      m_obstacle_buff.set_transparency(m_hint_buff_fill_transparency);
    }
    string spec = m_obstacle_buff.get_spec();
    postMessage("VIEW_POLYGON", spec, "buff");
  }
}


//-----------------------------------------------------------
// Procedure: postErasablePolygons

void BHV_AvoidObstacle::postErasablePolygons()
{
  if(m_obstacle_orig.is_convex()) {
    m_obstacle_orig.set_active(false);
    string spec = m_obstacle_orig.get_spec();
    postMessage("VIEW_POLYGON", spec, "orig");
  }
   
  if(m_obstacle_buff.is_convex() && (m_buffer_dist > 0)) {
    m_obstacle_buff.set_active(false);
    string spec = m_obstacle_buff.get_spec();
    postMessage("VIEW_POLYGON", spec, "buff");
  }
}

//-----------------------------------------------------------
// Procedure: updatePlatformInfo()

bool BHV_AvoidObstacle::updatePlatformInfo()
{
  bool ok1, ok2, ok3;
  m_osx = getBufferDoubleVal("NAV_X", ok1);
  m_osy = getBufferDoubleVal("NAV_Y", ok2);
  m_osh = getBufferDoubleVal("NAV_HEADING", ok3);

  if(!ok1 || !ok2) {
    postWMessage("No Ownship NAV_X and/or NAV_Y in info_buffer");
    return(false);
  }
  if(!ok3) {
    postWMessage("No Ownship NAV_HEADING in info_buffer");
    return(false);
  }
  return(true);
}

//----------------------------------------------------------------
// Procedure: applyBuffer

bool BHV_AvoidObstacle::applyBuffer()
{
  m_obstacle_buff = m_obstacle_orig;

  // Sanity check 1 - if buffer dist is zero, buffer poly is orig
  if(m_buffer_dist <= 0)
    return(false);

  // Sanity check 2 - if ownship in orig poly, buffer poly is orig
  if(m_obstacle_orig.contains(m_osx, m_osy))
    return(false);

  // Part 1: Build the buffer poly to spec size.
  m_obstacle_buff.grow_by_amt(m_buffer_dist);
  
  // Part 2: If ownship is currently in the buffer poly, then rebuild
  // the buffer poly by incrementally growing to the largest buffer
  // poly (up to m_buffer_dist) that does not contain ownship.
  if(m_obstacle_buff.contains(m_osx, m_osy)) {
    bool os_in_newb = false;
    for(unsigned int j=0; ((j<=100) && (!os_in_newb)); j++) {
      XYPolygon new_poly = m_obstacle_orig;
      double grow_amt = ((double)(j) / 100.0) * m_buffer_dist;
      new_poly.grow_by_amt(grow_amt);
      os_in_newb = new_poly.contains(m_osx, m_osy);
      if(!os_in_newb) 
	m_obstacle_buff = new_poly;
    }
  }

  // Part 3: Sanity check Parts 1 and 2. One way or another the buffer
  // poly should NOT contain ownship. Just double check that here.
  if(m_obstacle_buff.contains(m_osx, m_osy)) {
    m_obstacle_buff = m_obstacle_orig;
    return(false);
  }
  
  m_obstacle_buff.set_label(m_obstacle_orig.get_label() + "_buff");

  return(true);
}

//-----------------------------------------------------------
// Procedure: postConfigStatus

void BHV_AvoidObstacle::postConfigStatus()
{
  string str = "type=BHV_AvoidObstacles,name=" + m_descriptor;
  
  str += ",allowable_ttc="  + doubleToString(m_allowable_ttc,2);
  str += ",buffer_dist="   + doubleToString(m_buffer_dist,2);

  str += ",pwt_outer_dist=" + doubleToString(m_pwt_outer_dist,2);
  str += ",pwt_inner_dist=" + doubleToString(m_pwt_inner_dist,2);
  str += ",completed_dist=" + doubleToString(m_completed_dist,2);

  str += ",obstacle_key=" + m_obstacle_key;
  str += ",obtacle_update_var=" + m_obstacle_update_var;

  postRepeatableMessage("BHV_SETTINGS", str);
}
