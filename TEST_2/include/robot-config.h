using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor MOTOR_FR;
extern motor MOTOR_FL;
extern motor MOTOR_RR;
extern motor MOTOR_RL;
extern inertial INERTIAL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );