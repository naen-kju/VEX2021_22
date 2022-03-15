#include <Auton.h>

void drive(void)
{
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

    // Sets max and min Threshold for both Axis
    LThres = Controller1.Axis3.position(pct);
    RThres = Controller1.Axis2.position(pct);
    // Let >=90% = 100% for left and right
    if(LThres >= 90)
      LThres = 100;
    else if(LThres <= -90)
      LThres = -100;

    if(RThres >= 90)
      RThres = 100;
    else if(RThres <= -90)
      RThres = -100;

    // Let <=5% = 0% for left and right
    if(LThres <= 5)
      LThres = 0;
    else if(LThres >= -5)
      LThres = 0;

    if(RThres <= 5)
      RThres = 0;
    else if(RThres >= -5)
      RThres = -0;
    


    
      
    // Use wait to save resources
    wait(5, msec);
  }  
}