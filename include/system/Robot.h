
#pragma once
#include "RobotCfg.h"
#include "params.h"
// #include 
class Robot{
 public:
  typedef std::shared_ptr<Robot> Ptr;
  Robot();

  bool SeedRight();
  bool SeedLeft();
  bool StopSeed();

  bool PlantRight();
  bool PlantLeft();
  bool StopPlant();
  static Robot& GetInstance();


 private:
  uint32_t seed_counter_ = 0;
  uint32_t seed_stop_time_ = 0;
  uint32_t plant_counter_ = 0;
  uint32_t plant_stop_time_ = 0;

  uint32_t mixing_counter_ = 0;
  uint32_t mixing_time_ = 0;
  uint32_t mixing_stop_time_ = 0;

 public:
  // 播种方法
  bool seed(std::vector<std::pair<int, int>> data);

  // // 电机速度PID控制
  // // void MotorsPIDControl();
  // void controlMotorControl();
  void controlLeftMotor();
  void controlRightMotor();
  void controlTurnMotor();
  void controlLiftMotor();
  void resetMotorsPID();
  void resetLeftMotorPID();
  void resetRightMotorPID();
  void resetTurnMotorPID();
  void resetLiftMotorPID();
  void setLeftMotorSpeed(double speed);
  void setRightMotorSpeed(double speed);
  void setTurnMotorSpeed(double speed);
  void setLiftMotorSpeed(double speed);
  void setLeftMotorSpeedwithoutPID();
  void setRightMotorSpeedwithoutPID();
  void setTurnMotorSpeedwithoutPID();
  void setLiftMotorSpeedwithoutPID();
  void setLeftMotorProcess(int32_t process);
  void setRightMotorProcess(int32_t process);
  void setTurnMotorProcess(int32_t process);
  void setLiftMotorProcess(int32_t process);
  void setLeftMotorLastENCCounter(int32_t last_enc_counter);
  void setRightMotorLastENCCounter(int32_t last_enc_counter);
  void setTurnMotorLastENCCounter(int32_t last_enc_counter);
  void setLiftMotorLastENCCounter(int32_t last_enc_counter);


 public:
  PID::Ptr let_pid_;
  PID::Ptr right_pid_;
  PID::Ptr turn_pid_;
  PID::Ptr lift_pid_;
  double left_speed_without_PID_ = 0;
  double right_speed_without_PID_ = 0;
  double turn_speed_without_PID_ = 0;
  double lift_speed_without_PID_ = 0;
  void setLeftMotorSpeedWithoutPID(double speed) {
    left_speed_without_PID_ =speed;
  }

  void setRightMotorSpeedWithoutPID(double speed) {
    right_speed_without_PID_ =speed;
  }

  void setTurnMotorSpeedWithoutPID(double speed) {
    turn_speed_without_PID_ =speed;
  }

  void setLiftMotorSpeedWithoutPID(double speed) {
    lift_speed_without_PID_ =speed;
  }

  struct PIDTEMP {
    int32_t last_enc_counter = 0;
  };
  PIDTEMP left_pid_temp_;
  PIDTEMP right_pid_temp_;
  PIDTEMP turn_pid_temp_;
  PIDTEMP lift_pid_temp_;
// 读取传感器信号
  bool getStopsignal();

};
