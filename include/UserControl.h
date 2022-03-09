#include <Auton.h>

void YashMode(void)
{
  vexcodeInit();

  // Let Drive Motors Coast
  BRMtr.setBrake(coast);
  MRMtr.setBrake(coast);
  FRMtr.setBrake(coast);
  BLMtr.setBrake(coast);
  MLMtr.setBrake(coast);
  FLMtr.setBrake(coast);

  // While loop to avoid usercontrol from exiting
  while(true)
  {
    // Controls for drive wheels
    FLMtr.spin(fwd, Controller1.Axis3.position(pct),pct);
    MLMtr.spin(fwd, Controller1.Axis3.position(pct),pct);
    BLMtr.spin(fwd, Controller1.Axis3.position(pct),pct);
    FRMtr.spin(fwd, Controller1.Axis2.position(pct),pct);
    MRMtr.spin(fwd, Controller1.Axis2.position(pct),pct);
    BRMtr.spin(fwd, Controller1.Axis2.position(pct),pct);


    // Threshold for both Axis, let 90% = 100%
    leftThres = Controller1.Axis3.position(pct);
    if(leftThres > 90)
      leftThres = 100;
    else if(leftThres < -90)
      leftThres = -100;

    rightThres = Controller1.Axis2.position(pct);
    if(rightThres > 90)
      rightThres = 100;
    else if(rightThres < -90)
      rightThres = -100;
      
    // Use wait to save resources
    wait(5, msec);
  }  
}