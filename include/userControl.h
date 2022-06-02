#include "auton.h"

void drive(void)
{
  // Let Drive Motors Coast
  SetDrvBrake(coast);

  // While loop to avoid usercontrol from exiting
  while(true)
  {
    // Controls for all 6 drive wheels
    FLMtr.spin(fwd, leftY, pct);
    MLMtr.spin(fwd, leftY, pct);
    BLMtr.spin(fwd, leftY, pct);
    FRMtr.spin(fwd, rightY, pct);
    MRMtr.spin(fwd, rightY, pct);
    BRMtr.spin(fwd, rightY, pct);

    // Sets max and min Threshold for both Axis
    leftY = Controller1.Axis3.position(pct);
    rightY = Controller1.Axis2.position(pct);
    

    // Let >=90% = 100% for left and right
    if(leftY >= maxThres)
    {
      leftY = 100;
    }
    else if(leftY <= -maxThres)
      {
        leftY = -100;
      }

    if(rightY >= maxThres)
    {
      rightY = 100;
    }
    else if(rightY <= -maxThres)
      {
        rightY = -100;
      }

    // Let <=5% = 0% for left and right
    if(leftY <= minThres)
    {
      leftY = 0;
    }
    else if(leftY >= -minThres)
      {
        leftY = 0;
      }

    if(rightY <= minThres)
    {
      rightY = 0;
    }
      else if(rightY >= -minThres)
      {
        rightY = -0;
      }


    // Controls for Lift Motor (Buttons R1 and R2)
    if(Controller1.ButtonR2.pressing())
    {
      LiftMtr.spin(fwd, liftSpeed, rpm);
    }
    else if(Controller1.ButtonR1.pressing())
    {
      LiftMtr.spin(reverse, liftSpeed, rpm);
    }
    else
    {
      LiftMtr.stop();
    }

    // Controls for Chain Motor (Buttons L1 and L2)
    if(Controller1.ButtonL2.pressing())
    {
      ChainMtr.spin(fwd, chainSpeed, rpm);
    }
    else if(Controller1.ButtonL1.pressing())
    {
      ChainMtr.spin(reverse, chainSpeed, rpm);
    }
    else
    {
      LiftMtr.stop();
    }


    // Use wait to save resources
    wait(5, msec);
  }  
}
