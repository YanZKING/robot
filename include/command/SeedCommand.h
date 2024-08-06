/**
 * @file SeedCommand.h
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

class SeedCommand : public CommandBase {
 public:
  typedef std::shared_ptr<SeedCommand> Ptr;
  SeedCommand(std::vector<std::pair<int, int>> data): data_(data) {}
  void initialize() override ;
  void execute() override;
  void end() override;
  bool isFinished() override;
 private:
  bool is_finished = false;
  int64_t m_last_time;
  std::vector<std::pair<int, int>> data_;

};

