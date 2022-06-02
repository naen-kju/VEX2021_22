#include "vex.h"

/*//////////////////////////////////////////////////
  Functions below for other parts of code.
*///////////////////////////////////////////////////

float         leftY,                        // Sets left joystick as a variable
              rightY,                       // Sets right joystick as a variable
              liftSpeed = 100,
              chainSpeed = 100;

const float   maxThres {90},                // Sets maximum threshold, used for joystick
              minThres {5},                 // Sets minimum threshold, used for joystick
              Deg2Rad = M_PI / 180,         // Conversion from degrees to radians
              liftGR   {7},                 // 7:1 Gear Ratio for back lift/scoop
              mogoGR   {5},                 // 5:1 Gear Ratio for front claw
              driveGR  {84/60},             // 84:60 Gear Ratio for drive wheels
              wheelDia {4},                 // Measurement in inches (in)
              wheelCirc = wheelDia * M_PI;  // The equation to find the circumfrence of a circle


// Sets all drive motors to indicted vex::brakeType
void SetDrvBrake(brakeType type)
{
  BRMtr.setBrake(type);
  MRMtr.setBrake(type);
  FRMtr.setBrake(type);
  BLMtr.setBrake(type);
  MLMtr.setBrake(type);
  FLMtr.setBrake(type);
}

// Conversion for inches to degrees for drive wheels
float inch2deg (float dist)
{
  float Num = ((dist/wheelCirc) * 360) * driveGR;
  return Num;
}

//Uses .spin command to program timed functions and for any other scenario
void SpinDriveMtrs (float lVel, float rVel)
{
  FLMtr.spin(reverse, lVel, rpm);
  MLMtr.spin(fwd, lVel, rpm);
  BLMtr.spin(fwd, lVel, rpm);

  FRMtr.spin(fwd, rVel, rpm);
  MRMtr.spin(fwd, rVel, rpm);
  BRMtr.spin(fwd, rVel, rpm);
}

//Stop all motors of robot for whatever scenario.
void StopDrv (bool LMtrs, bool RMtrs)
{
  if(LMtrs == true)
  { 
    FLMtr.stop();
    MLMtr.stop();
    BLMtr.stop();
  }

  if(RMtrs == true)
  {
    FRMtr.stop();
    MRMtr.stop();
    BRMtr.stop();
  }
}

//Uses .spinFor command to program timed functions and for any other scenario
void SpinForDriveMtrs (float lDeg, float rDeg, float lVel, float rVel, bool next)
{
  FRMtr.spinFor(fwd, lDeg, deg, lVel, rpm, false); 
  MLMtr.spinFor(fwd, lDeg, deg, lVel, rpm, false);
  BLMtr.spinFor(fwd, lDeg, deg, lVel, rpm, false);

  FRMtr.spinFor(fwd, rDeg, deg, rVel, rpm, false);
  MRMtr.spinFor(fwd, rDeg, deg, rVel, rpm, false);
  BRMtr.spinFor(fwd, rDeg, deg, rVel, rpm, next);
}

/*//////////////////////////////////////////////////
  Functions for auton.h based on time
*///////////////////////////////////////////////////

void TimeDrv (float Lvel, float Rvel, float milsec)
{
  SpinDriveMtrs (Lvel, Rvel);

  wait (milsec, msec);
  
  StopDrv(true, true);
}

/*//////////////////////////////////////////////////
  Functions for auton.h based on degree changes
*///////////////////////////////////////////////////

void DegDrv (float vel, float dist, bool next)
{
  float rot = inch2deg(dist);
  SpinForDriveMtrs(rot, rot, vel, vel, next);
}

void DegTurn();

/*//////////////////////////////////////////////////
  Functions for auton.h based on inertial sensor
*///////////////////////////////////////////////////

void SpinnyDrv();