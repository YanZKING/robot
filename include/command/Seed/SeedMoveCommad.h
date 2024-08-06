/**
 * @file SeedMoveCommad.h
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
#include "command/MotorPIDCommand.h"
using namespace std;
using namespace RobotGenius;

class SeedMoveCommad : public CommandBase {
 public:
  typedef std::shared_ptr<SeedMoveCommad> Ptr;
  SeedMoveCommad(double speed = 30): speed_(speed) {}
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;
  double speed_;
  bool last_sigal = true;
  bool flag_  = false;

};
