#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FRMtr = motor(PORT6, ratio6_1, false);
motor MRMtr = motor(PORT3, ratio6_1, true);
motor BRMtr = motor(PORT4, ratio6_1, false);
motor FLMtr = motor(PORT8, ratio6_1, true);
motor MLMtr = motor(PORT9, ratio6_1, false);
motor BLMtr = motor(PORT10, ratio6_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}