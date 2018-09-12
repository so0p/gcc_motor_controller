#ifndef ThingSuite_h
#define ThingSuite_h
//class JoystickSuite;
#include "../JoystickSuite/JoystickSuite.h"
//#include <SoftwareSerial.h>

class ThingSuite {
  public:
  
  // *******************************
  // Constructors & Member Functions       
  // *******************************

  ThingSuite();

  void getThing(JoystickSuite& joystick);
  void setThingSpeed(JoystickSuite& joystick);
  
  // *********************
  // Thing Struct        
  // *********************

  typedef struct{
  int direction; //  accessed by setThingSpeed & checked by getThing
  int motorNum; // accessed by getThing
  int duration; // ??
  }THING_PARAMS;

  THING_PARAMS commands_to_mc;

  // **********
  // DEBUG MODE
  // ********** 

  bool debugMode = false;                // Enabled/Disables debug messages
  
  // *******************************
  // Global Variables       
  // *******************************
  
  bool thing_on; // getThing checks this value
  long lastTimeThingMessageRecieved; //= millis(); //moved to ThingSuite.h
};
#endif // THINGSUITE_H