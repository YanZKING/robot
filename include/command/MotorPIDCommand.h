/**
 * @file MotorPIDCommand.h
 * @author jiapeng.lin (jiapeng.lin@high-genius.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "robotgenius/RobotGenius.h"
#include "RobotCfg.h"
#include "params.h"
#include "system/Robot.h"
using namespace std;
using namespace RobotGenius;


class LeftMotorPIDCommand : public CommandBase {
 public:
  typedef std::shared_ptr<LeftMotorPIDCommand> Ptr;
  LeftMotorPIDCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class RightMotorPIDCommand : public CommandBase {
 public:
  typedef std::shared_ptr<RightMotorPIDCommand> Ptr;
  RightMotorPIDCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class TurnMotorPIDCommand : public CommandBase {
 public:
  typedef std::shared_ptr<TurnMotorPIDCommand> Ptr;
  TurnMotorPIDCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class LiftMotorPIDCommand : public CommandBase {
 public:
  typedef std::shared_ptr<LiftMotorPIDCommand> Ptr;
  LiftMotorPIDCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};
class LeftMotorCommand : public CommandBase {
 public:
  typedef std::shared_ptr<LeftMotorCommand> Ptr;
  LeftMotorCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class RightMotorCommand : public CommandBase {
 public:
  typedef std::shared_ptr<RightMotorCommand> Ptr;
  RightMotorCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class TurnMotorCommand : public CommandBase {
 public:
  typedef std::shared_ptr<TurnMotorCommand> Ptr;
  TurnMotorCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};

class LiftMotorCommand : public CommandBase {
 public:
  typedef std::shared_ptr<LiftMotorCommand> Ptr;
  LiftMotorCommand();
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;

};
