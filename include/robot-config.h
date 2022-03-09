using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FRMtr;
extern motor MRMtr;
extern motor BRMtr;
extern motor FLMtr;
extern motor MLMtr;
extern motor BLMtr;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );