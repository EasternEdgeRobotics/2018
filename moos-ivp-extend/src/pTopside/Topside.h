/************************************************************/
/*    NAME: eer                                              */
/*    ORGN: MIT                                             */
/*    FILE: Topside.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Topside_HEADER
#define Topside_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class Topside : public CMOOSApp
{
 public:
   Topside();
   ~Topside();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
