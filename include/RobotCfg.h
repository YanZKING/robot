#pragma once
#include "robotgenius/RobotGenius.h"
using namespace std;
using namespace RobotGenius;
using namespace VMX;
using namespace Titan;
// 底盘左轮电机
extern  Motor::ptr LeftMotor;
extern  ENC::ptr LeftENC;
// 底盘右轮电机
extern  Motor::ptr RightMotor;
extern  ENC::ptr RightENC;
// OMS旋转电机
extern  Motor::ptr TurnMotor;
extern  ENC::ptr TurnENC;
// OMS升降电机
extern  Motor::ptr LiftMotor;
extern  ENC::ptr LiftENC;
// 开关舵机
extern  PWM::ptr SwitchServo ;
// 搅拌舵机
extern  PWM::ptr MixingServo;
// 旋转播种舵机
extern  PWM::ptr SeedingServo;

// 升降限位
extern  DI::ptr LiftLimit;
// 播种触发限位
extern  DI::ptr SeedingLimit;

// 急停触发限位
extern  DI::ptr StopLimit;