#include "system/Robot.h"
using namespace std;
using namespace RobotGenius;
class CommandTest : public CommandBase {
 public:
  typedef std::shared_ptr<CommandTest> Ptr;
  CommandTest(std::string name) :m_name(name){}
  void initialize() override {
    StopLimit->read();
    bot.StopPlant();
    bot.StopSeed();
    data.push_back(std::make_pair(1, 0));
    data.push_back(std::make_pair(2, 1));
    // data.push_back(std::make_pair(1, 1));
    // data.push_back(std::make_pair(0, 0));
    std::cout << m_name << " initialize" << std::endl;
  }


  void execute()override {
    static int counter = 0;
    static bool seed_end = false;
    static bool plant_end = false;
    auto index = data[counter];
    if(index.first == 1) {
      if (!seed_end) {
        seed_end = bot.SeedRight();
      } else {
        if (index.second == 1) {
          if (!plant_end) {
            plant_end = bot.PlantRight();
          } else {
            if (bot.StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } else {
          if (!plant_end) {
            plant_end = bot.PlantLeft();
          } else {
            if (bot.StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } 
      }
    } else if (index.first == 0) {
      if (!seed_end) {
        seed_end = bot.SeedLeft();
      } else {
        if (index.second == 1) {
          if (!plant_end) {
            plant_end = bot.PlantRight();
          } else {
            if (bot.StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } else {
          if (!plant_end) {
            plant_end = bot.PlantLeft();
          } else {
            if (bot.StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        }
      }
    } else {
      bot.StopPlant();
      bot.StopSeed();
      plant_end = false;
      seed_end = false;
      counter++;
    }
    is_finished = !StopLimit->read();
    if (counter > data.size() -1) {
      bot.StopPlant();
      bot.StopSeed();
      is_finished = true;
      plant_end = false;
      seed_end = false;
    }
    std::cout << GetCurrentMS() - m_last_time<< std::endl;
    m_last_time =  GetCurrentMS();

    // counter++;
  }
  void end() override{
    std::cout <<  m_name << "end" << std::endl;
  }
  bool isFinished() override {
    if(counter > 1000 ) {
      is_finished = true;
    }
    return is_finished;
  }
 private:
  std::string m_name;
  int counter = 0;
  bool is_finished = false;
  uint8_t m_sleep_time;
  int64_t m_last_time;
  // seed:0 1 左右
    // plant:0 1 左右
  std::vector<std::pair<int, int>> data;
  Robot bot;

};
int main() {

  Scheduler::GetInstance(1, false).start();
  sleep(1); 
  CommandTest::Ptr command0 = std::make_shared<CommandTest>("TestLimit");
  
  
  command0->withTimer(20)->schedule();
  // sleep(1); 
  sleep(3);
  Scheduler::GetInstance().stop();
  return 0;
}

