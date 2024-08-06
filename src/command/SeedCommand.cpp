#include "command/SeedCommand.h"


void SeedCommand::initialize() {
  is_finished = false;
  // Robot::GetInstance().setLeftMotorSpeedWithoutPID(0);
  // Robot::GetInstance().setRightMotorSpeedWithoutPID(0);
}
void SeedCommand::execute() {
  Robot::GetInstance().setLeftMotorSpeed(0);
  Robot::GetInstance().setRightMotorSpeed(0);
  is_finished = Robot::GetInstance().seed(data_);

}
void SeedCommand::end() {
  // std::cout << "SeedCommand:endl" <<std::endl;
}
bool SeedCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}
