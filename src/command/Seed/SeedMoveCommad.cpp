#include "command/Seed/SeedMoveCommad.h"
#include "RobotCfg.h"
void SeedMoveCommad::initialize() {
  flag_ = false;
}
void SeedMoveCommad::execute() {
// 按钮按下去是false
  // static bool flag = false;
  SeedingLimit->read();
  is_finished = SeedingLimit->get() && ! last_sigal;
  last_sigal = SeedingLimit->get();
  if (!is_finished || flag_) {
    Robot::GetInstance().setLiftMotorSpeedWithoutPID(SEEDLIFTPWM);
    Robot::GetInstance().setLeftMotorSpeed(SEEDMOTORSPEED);
    Robot::GetInstance().setRightMotorSpeed(-SEEDMOTORSPEED);
    return;
  }
  flag_ = true;
  is_finished =- true;

}
void SeedMoveCommad::end() {
  Robot::GetInstance().setLeftMotorSpeed(0);
  Robot::GetInstance().setRightMotorSpeed(0);
  // std::cout << "SeedMoveCommad end" << std::endl;
  flag_  =false;
}
bool SeedMoveCommad::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}