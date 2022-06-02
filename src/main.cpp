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
// FrontAir             digital_out   A               
// BackAirL             digital_out   B               
// BackAirR             digital_out   C               
// LiftMtr              motor         1               
// ChainMtr             motor         2               
// Spinny               inertial      5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "userControl.h" /* #include order:
                            <math.h>
                            <stdio.h>
                            <stdlib.h>
                            <string.h>
                            "v5.h"
                            "v5_vcs.h"
                            "robot-config.h"
                            "vex.h"
                            "functions.h"
                            "preAuton.h"
                            "auton.h"
                            "userControl.h" */
                          
competition comp;

int main() // Execution start when program is run
{
  // Calibrates inertial sensor at startup.
  Spinny.calibrate();


  // Set up callbacks for autonomous and driver control periods.
  comp.autonomous(auton);
  comp.drivercontrol(drive);

  // Run the pre-autonomous function.
  pre_auton();

  while (true) // Prevent main from exiting with an infinite loop.
  {
    // Use wait to save resources.
    wait(5, msec);
  }
}