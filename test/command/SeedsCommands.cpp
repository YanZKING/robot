#include "command/SeedCommand.h"
#include <memory>
#include "command/Seed/SeedMoveCommad.h"
using namespace RobotGenius;
int main() {
  
  Scheduler::GetInstance(2, false).start();
  sleep(1); 
  LeftMotorPIDCommand::Ptr command0 = std::make_shared<LeftMotorPIDCommand>();
  RightMotorPIDCommand::Ptr command1 = std::make_shared<RightMotorPIDCommand>();
  LiftMotorCommand::Ptr command7 = std::make_shared<LiftMotorCommand>();
  std::vector<std::pair<int, int>> initData = {{1, 0}, {0, 1}};
  SequentialCommandGroup::Ptr S = std::make_shared<SequentialCommandGroup>();
  for (int i = 0; i < 1; i ++) {
    SeedMoveCommad::Ptr command3 = std::make_shared<SeedMoveCommad>();
    SeedCommand::Ptr command4 = std::make_shared<SeedCommand>(initData);
    S->AddCommands(command3->withTimer(20),command4->withTimer(20));
  }
  ParallelDeadlineGroup::Ptr DG = std::make_shared<ParallelDeadlineGroup>();
  DG->AddCommands(command0->withTimer(20),command1->withTimer(20),command7->withTimer(20));
  DG->setDeadlineCommand(S);
  DG->schedule();
  sleep(3);
  Scheduler::GetInstance().stop();
  return 0;
}