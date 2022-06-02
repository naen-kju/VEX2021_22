#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FRMtr = motor(PORT20, ratio18_1, false);
motor MRMtr = motor(PORT19, ratio18_1, true);
motor BRMtr = motor(PORT18, ratio18_1, false);
motor FLMtr = motor(PORT1, ratio18_1, true);
motor MLMtr = motor(PORT2, ratio18_1, false);
motor BLMtr = motor(PORT3, ratio18_1, true);
controller Controller1 = controller(primary);
digital_out FrontAir = digital_out(Brain.ThreeWirePort.A);
digital_out BackAirL = digital_out(Brain.ThreeWirePort.B);
digital_out BackAirR = digital_out(Brain.ThreeWirePort.C);
motor LiftMtr = motor(PORT1, ratio18_1, false);
motor ChainMtr = motor(PORT2, ratio18_1, false);
inertial Spinny = inertial(PORT15);

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