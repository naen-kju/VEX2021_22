// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FRMtr                motor         6               
// MRMtr                motor         3               
// BRMtr                motor         4               
// FLMtr                motor         8               
// MLMtr                motor         9               
// BLMtr                motor         10              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

/*  
include order:
  robot-config.h
  vex.h
  Functions.h
  PreAuton.h
  Auton.h
  UserControl.h
*/
#include <UserControl.h>

competition Comp;

int main() 
{
  // Set up callbacks for autonomous and driver control periods.
  Comp.autonomous(BryanMode);
  Comp.drivercontrol(YashMode);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(5, msec);
  }  
}