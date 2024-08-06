#include "command/Seed/SeedMoveCommad.h"


int main() {
  Scheduler::GetInstance(1, false).start();
  sleep(1); 
  LeftMotorPIDCommand::Ptr command0 = std::make_shared<LeftMotorPIDCommand>();
  RightMotorPIDCommand::Ptr command1 = std::make_shared<RightMotorPIDCommand>();
  SeedMoveCommad::Ptr command3 = std::make_shared<SeedMoveCommad>();
  command0->withTimer(20)->schedule();
  command1->withTimer(20)->schedule();
  command3->withTimer(20)->schedule();
  sleep(3);
  Scheduler::GetInstance().stop();
  return 0;
}