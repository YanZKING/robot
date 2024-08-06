#include "command/SeedCommand.h"
#include <memory>
int main() {
  
  Scheduler::GetInstance(1, false).start();
  sleep(1); 
  std::vector<std::pair<int, int>> initData = {{1, 0}, {0, 1}};
  SeedCommand::Ptr command0 = std::make_shared<SeedCommand>(initData);
  command0->withTimer(20)->schedule();
  sleep(3);
  Scheduler::GetInstance().stop();
  return 0;
}