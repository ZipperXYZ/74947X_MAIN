// WRITED BY GABRIEL BOSSÉ 2023-06-06 \\


#include "math.h"
#include "stdio.h"
#include "time.h"
#include "vex.h"
#include "vex_imu.h"
#include "MiniPID.h"
#include "vex_task.h"

using namespace vex;

struct DRIVE_TRAIN
{
  motor MOTOR_FR;
  motor MOTOR_FL;
  motor MOTOR_RR;
  motor MOTOR_RL;
  inertial INERTIAL;
  double P;
  double I;
  double D;
  bool PID_ENABLED = false;

  void Pid_loop(){
    while (1){
        if (PID_ENABLED == true){
            int DRIVE_AVERAGE = (RIGHT_SIDE.position(degrees)+RIGHT_SIDE.position(degrees))/2;
            int TURN_AVERAGE = (RIGHT_SIDE.position(degrees)-RIGHT_SIDE.position(degrees));
            OUTPUT_DRIVE = DRIVE_PID.getOutput(DRIVE_AVERAGE,DESIRED_DRIVE);
            OUTPUT_TURN = TURN_PID.getOutput(TURN_AVERAGE,DESIRED_TURN);
            RIGHT_SIDE.spin(forward,OUTPUT_DRIVE+OUTPUT_TURN,voltageUnits::volt);
            LEFT_SIDE.spin(forward,OUTPUT_DRIVE-OUTPUT_TURN,voltageUnits::volt);
        }
    }
  }

  void Drive_for(){

  }

  void Turn_for(){
    
  }

  double Get_angle(){
    return INERTIAL.angle();
  }

  private:
    MiniPID DRIVE_PID=MiniPID(P,I,D);
    MiniPID TURN_PID=MiniPID(P,I,D);
    motor_group RIGHT_SIDE = motor_group(MOTOR_RR,MOTOR_FR);
    motor_group LEFT_SIDE = motor_group(MOTOR_RL,MOTOR_FL);
    double OUTPUT_DRIVE;
    double OUTPUT_TURN;
    double DESIRED_DRIVE = 0;
    double DESIRED_TURN = 0;
};