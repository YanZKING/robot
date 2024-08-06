#include "command/MotorPIDCommand.h"
#include "RobotCfg.h"
#include "params.h"


LeftMotorPIDCommand::LeftMotorPIDCommand(){

}
void LeftMotorPIDCommand::initialize() {
  is_finished = false;
}
void LeftMotorPIDCommand::execute() {
  Robot::GetInstance().setLeftMotorProcess(LeftENC->read());
  Robot::GetInstance().controlLeftMotor();
  Robot::GetInstance().setLeftMotorLastENCCounter(LeftENC->get());

}
void LeftMotorPIDCommand::end() {
  // std::cout << "LeftMotorPIDCommand end" << std::endl;
}
bool LeftMotorPIDCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}

RightMotorPIDCommand::RightMotorPIDCommand(){

}

void RightMotorPIDCommand::initialize() {
  is_finished = false;
}

void RightMotorPIDCommand::execute() {
  Robot::GetInstance().setRightMotorProcess(RightENC->read());
  Robot::GetInstance().controlRightMotor();
  Robot::GetInstance().setRightMotorLastENCCounter(RightENC->get());
}

void RightMotorPIDCommand::end() {
  // std::cout << "RightMotorPIDCommand end" << std::endl;
}

bool RightMotorPIDCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}


TurnMotorPIDCommand::TurnMotorPIDCommand(){

}

void TurnMotorPIDCommand::initialize() {
  is_finished = false;
}

void TurnMotorPIDCommand::execute() {
  Robot::GetInstance().setTurnMotorProcess(TurnENC->read());
  Robot::GetInstance().controlTurnMotor();
  Robot::GetInstance().setTurnMotorLastENCCounter(TurnENC->get());
}

void TurnMotorPIDCommand::end() {
  return;
}

bool TurnMotorPIDCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}

LiftMotorPIDCommand::LiftMotorPIDCommand(){

}

void LiftMotorPIDCommand::initialize() {
  is_finished = false;
}

void LiftMotorPIDCommand::execute() {
  Robot::GetInstance().setLiftMotorProcess(LiftENC->read());
  Robot::GetInstance().controlLiftMotor();
  Robot::GetInstance().setLiftMotorLastENCCounter(LiftENC->get());
}

void LiftMotorPIDCommand::end() {
  return;
}

bool LiftMotorPIDCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}


LeftMotorCommand::LeftMotorCommand(){

}

void LeftMotorCommand::initialize() {
  is_finished = false;
}

void LeftMotorCommand::execute() {
  Robot::GetInstance().setLeftMotorSpeedwithoutPID();
}

void LeftMotorCommand::end() {
  return;
}

bool LeftMotorCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}


RightMotorCommand::RightMotorCommand(){

}

void RightMotorCommand::initialize() {
  is_finished = false;
}

void RightMotorCommand::execute() {
  Robot::GetInstance().setRightMotorSpeedwithoutPID();
}

void RightMotorCommand::end() {
  return;
}

bool RightMotorCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}

TurnMotorCommand::TurnMotorCommand() {

}

void TurnMotorCommand::initialize() {
  is_finished = false;
}

void TurnMotorCommand::execute() {
  Robot::GetInstance().setTurnMotorSpeedwithoutPID();
}


void TurnMotorCommand::end() {
  return;
}

bool TurnMotorCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}

LiftMotorCommand::LiftMotorCommand() {

}

void LiftMotorCommand::initialize() {
  is_finished = false;
}

void LiftMotorCommand::execute() {
  Robot::GetInstance().setLiftMotorSpeedwithoutPID();
}

void LiftMotorCommand::end() {
  // std::cout << "LiftMotorCommand end" << std::endl;
}

bool LiftMotorCommand::isFinished() {
  if(Robot::GetInstance().getStopsignal()) {
    stopAll();
  }
  return is_finished || Robot::GetInstance().getStopsignal();
}
