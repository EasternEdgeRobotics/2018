/************************************************************/
/*    NAME: eer                                              */
/*    ORGN: MIT                                             */
/*    FILE: RasPi.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef RasPi_HEADER
#define RasPi_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class RasPi : public CMOOSApp
{
 public:
   RasPi();
   ~RasPi();

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
