
#include "RobotCfg.h"
using namespace std;
using namespace RobotGenius;
using namespace VMX;
using namespace Titan;
// 底盘左轮电机
Motor::ptr LeftMotor = std::make_shared<Motor>(2);
ENC::ptr LeftENC = std::make_shared<ENC>(2);
// 底盘右轮电机
Motor::ptr RightMotor = std::make_shared<Motor>(0);
ENC::ptr RightENC = std::make_shared<ENC>(0);
// OMS旋转电机
Motor::ptr TurnMotor = std::make_shared<Motor>(1);
ENC::ptr TurnENC = std::make_shared<ENC>(1);
// OMS升降电机
Motor::ptr LiftMotor = std::make_shared<Motor>(3);
ENC::ptr LiftENC = std::make_shared<ENC>(3);
// 开关舵机
PWM::ptr SwitchServo = std::make_shared<PWM>(14,100);
// 搅拌舵机
PWM::ptr MixingServo = std::make_shared<PWM>(15,100);
// 旋转播种舵机
PWM::ptr SeedingServo = std::make_shared<PWM>(16,100);

// 升降限位
DI::ptr LiftLimit = std::make_shared<DI>(9);
// 播种触发限位
DI::ptr SeedingLimit = std::make_shared<DI>(11);

// 急停触发限位
DI::ptr StopLimit = std::make_shared<DI>(10);