/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Gabriel Bosse                                    */
/*    Created:      Tue May 30 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor9               motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "sys/_intsup.h"
#include "vex.h"
#include "MAIN_CLASS.h"
#include "vex_global.h"

using namespace vex;

int * ChoosedAuto = 0;

int whenStarted1() {
  DRIVE_TRAIN Drive_train;
  Drive_train.P = 0.008;
  Drive_train.I = 0;
  Drive_train.D = 0;
  Drive_train.PORT_FL = PORT1;
  Drive_train.PORT_FR = PORT2;
  Drive_train.PORT_RR = PORT3;
  Drive_train.PORT_RL = PORT4;
  Drive_train.PORT_INERTIAL = PORT5;
  return 0;
}

int Auto0() {
  return 0;
}
int Auto1() {
  return 0;
}
int Auto2() {
  return 0;
}
int Auto3() {
  return 0;
}

int autonomus[] = {Auto0(),Auto1(),Auto2(),Auto3()};

int AutonomusChoising(){
  int lenght = sizeof(autonomus);
  if(autonomus == lenght)
  return 0;
}


//int WHEN_STARTED{

    //#return 0;
//}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();  
  whenStarted1();
}
