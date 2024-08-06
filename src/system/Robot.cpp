#include "system/Robot.h"
#include "params.h"
// #include "RobotCfg.h"
Robot::Robot() {
  let_pid_ = std::make_shared<PID>(PIDDT);
  right_pid_ = std::make_shared<PID>(PIDDT);
  turn_pid_ = std::make_shared<PID>(PIDDT);
  lift_pid_ = std::make_shared<PID>(PIDDT);
}
Robot& Robot::GetInstance() {
  static Robot robot;
  return robot;
}
bool Robot::SeedRight() {
  SeedingServo->setDutyCycle(SEEDRIGHT);
  if (seed_counter_ > SEEDTIMEINTERVAL) {
    seed_counter_ = 0;
    return true;
  }
  seed_counter_++;
  return false;
}
bool Robot::SeedLeft() {
  SeedingServo->setDutyCycle(SEEDLEFT);
  if (seed_counter_ > SEEDTIMEINTERVAL) {
    seed_counter_ = 0;
    return true;
  }
  seed_counter_++;
  return false;
}
bool Robot::StopSeed() {
  SeedingServo->setDutyCycle(SEEDMIDDLE);
  if (seed_stop_time_ > SEEDSTOPTERVAL) {
    seed_stop_time_ = 0;
    return true;
  }
  seed_stop_time_++;
  return false;
}

bool Robot::PlantRight() {
  static bool flag = true;
  if (flag) {
    MixingServo->setDutyCycle(PlANTRIGHTUP);
    if (mixing_counter_ > MIXINGCOUNTER) {
      mixing_counter_ = 0;
      flag = false;
    }
  } else {
    MixingServo->setDutyCycle(PlANTRIGHTDOWN);
    if (mixing_counter_ > MIXINGCOUNTER) {
      mixing_counter_ = 0;
      flag = true;
    }
  }
  mixing_counter_++;
  if (mixing_time_ > MIXINGTIMEINTERVAL) {
    mixing_time_ = 0;
    mixing_counter_ = 0;
    flag = true;
    return true;
  }
  mixing_time_++;
  return false;
}
bool Robot::PlantLeft() {
  static bool flag = true;
  if (flag) {
    MixingServo->setDutyCycle(PLANTLEFTUP);
    if (mixing_counter_ > MIXINGCOUNTER) {
      mixing_counter_ = 0;
      flag = false;
    }
  } else {
    MixingServo->setDutyCycle(PLANTLEFTDOWN);
    if (mixing_counter_ > MIXINGCOUNTER) {
      mixing_counter_ = 0;
      flag = true;
    }
  }
  mixing_counter_++;
  if (mixing_time_ > MIXINGTIMEINTERVAL) {
    mixing_time_ = 0;
    mixing_counter_ = 0;
    flag = true;
    return true;
  }
  mixing_time_++;
  return false;
}
bool Robot::StopPlant() {
  MixingServo->setDutyCycle(MIXINGMIDDLE);
  if (mixing_stop_time_ > MIXINGSTOPTIME) {
    mixing_stop_time_ = 0;
    return true;
  }
  mixing_stop_time_++;
  return false;
}

bool Robot::seed(std::vector<std::pair<int, int>> data) {
    static int counter = 0;
    static bool seed_end = false;
    static bool plant_end = false;
    auto index = data[counter];
    if(index.first == 1) {
      if (!seed_end) {
        seed_end = SeedRight();
      } else {
        if (index.second == 1) {
          if (!plant_end) {
            plant_end = PlantRight();
          } else {
            if (StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } else {
          if (!plant_end) {
            plant_end = PlantLeft();
          } else {
            if (StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } 
      }
    } else if (index.first == 0) {
      if (!seed_end) {
        seed_end = SeedLeft();
      } else {
        if (index.second == 1) {
          if (!plant_end) {
            plant_end = PlantRight();
          } else {
            if (StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        } else {
          if (!plant_end) {
            plant_end = PlantLeft();
          } else {
            if (StopPlant()) {
              plant_end = false;
              seed_end = false;
              counter++;
            }
          }
        }
      }
    } else {
      StopPlant();
      StopSeed();
      plant_end = false;
      seed_end = false;
      counter = 0;
      counter++;
    }
    if (counter > data.size() -1) {
      StopPlant();
      StopSeed();
      plant_end = false;
      seed_end = false;
      counter = 0;
      return true;
    }
    return false;
}




void Robot::controlLeftMotor() {
  static PIDParams left_pid_param = LEFTMOTORPID;
  static PIDOutputLimits left_output_limits = LEFTMOTOROUTPUTLIMITS;
  let_pid_->setGains(left_pid_param.kp, left_pid_param.ki, left_pid_param.kd);
  let_pid_->setOutputLimits(left_output_limits.min, left_output_limits.max);
  let_pid_->calculate();
  LeftMotor->setSpeedAndDir((abs(let_pid_->m_output)), let_pid_->m_output > 0 ,let_pid_->m_output < 0);
}
void Robot::controlRightMotor() {
  static PIDParams right_pid_param = RIGHTMOTORPID;
  static PIDOutputLimits right_output_limits = RIGHTMOTOROUTPUTLIMITS;
  right_pid_->setGains(right_pid_param.kp, right_pid_param.ki, right_pid_param.kd);
  right_pid_->setOutputLimits(right_output_limits.min, right_output_limits.max);
  right_pid_->calculate();
  RightMotor->setSpeedAndDir((abs(right_pid_->m_output)), right_pid_->m_output > 0 ,right_pid_->m_output < 0);
}
void Robot::controlTurnMotor() {
  static PIDParams turn_pid_param = TURNMOTORPID;
  static PIDOutputLimits turn_output_limits = TURNMOTOROUTPUTLIMITS;
  turn_pid_->setGains(turn_pid_param.kp, turn_pid_param.ki, turn_pid_param.kd);
  turn_pid_->setOutputLimits(turn_output_limits.min, turn_output_limits.max);
  turn_pid_->calculate();
  TurnMotor->setSpeedAndDir((abs(turn_pid_->m_output)), turn_pid_->m_output > 0 ,turn_pid_->m_output < 0);
}
void Robot::controlLiftMotor() {
  static PIDParams lift_pid_param = LIFTMOTORPID;
  static PIDOutputLimits lift_output_limits = LIFTMOTOROUTPUTLIMITS;
  lift_pid_->setGains(lift_pid_param.kp, lift_pid_param.ki, lift_pid_param.kd);
  lift_pid_->setOutputLimits(lift_output_limits.min, lift_output_limits.max);
  lift_pid_->calculate();
  LiftMotor->setSpeedAndDir((abs(lift_pid_->m_output)), lift_pid_->m_output > 0 ,lift_pid_->m_output < 0);
}
void Robot::resetMotorsPID() {
  let_pid_->reset();
  right_pid_->reset();
  turn_pid_->reset();
  lift_pid_->reset(); 
}
void Robot::resetLeftMotorPID() {
  let_pid_->reset();
  left_pid_temp_.last_enc_counter = 0;
}
void Robot::resetRightMotorPID() {
  right_pid_->reset();
  right_pid_temp_.last_enc_counter = 0;
}
void Robot::resetTurnMotorPID() {
  turn_pid_->reset();
  turn_pid_temp_.last_enc_counter = 0;
}
void Robot::resetLiftMotorPID() {
  lift_pid_->reset();
  lift_pid_temp_.last_enc_counter = 0;
}


bool Robot::getStopsignal() {
  return !StopLimit->read();
}

void Robot::setLeftMotorSpeed(double speed) {
  let_pid_->setSetpoint(speed);

}
void Robot::setRightMotorSpeed(double speed){
  right_pid_->setSetpoint(speed);
}
void Robot::setTurnMotorSpeed(double speed) {
  turn_pid_->setSetpoint(speed);
}
void Robot::setLiftMotorSpeed(double speed) {
  lift_pid_->setSetpoint(speed);
}

void Robot::setLeftMotorProcess(int32_t process) {
  // std::cout << "left_pid_temp_.last_enc_counter:" << process - left_pid_temp_.last_enc_counter << std::endl;
  let_pid_->setProcess(process - left_pid_temp_.last_enc_counter);
}
void Robot::setRightMotorProcess(int32_t process) {
  right_pid_->setProcess(process - right_pid_temp_.last_enc_counter);
}

void Robot::setTurnMotorProcess(int32_t process) {
  turn_pid_->setProcess(process - turn_pid_temp_.last_enc_counter);
}

void Robot::setLiftMotorProcess(int32_t process) {
  lift_pid_->setProcess(process - lift_pid_temp_.last_enc_counter);
}

void Robot::setLeftMotorLastENCCounter(int32_t last_enc_counter) {
  
  left_pid_temp_.last_enc_counter = last_enc_counter;
    // std::cout << "left_pid_temp_.last_enc_counter_2:" << left_pid_temp_.last_enc_counter << std::endl;
}

void Robot::setRightMotorLastENCCounter(int32_t last_enc_counter) {
  right_pid_temp_.last_enc_counter = last_enc_counter;
}

void Robot::setTurnMotorLastENCCounter(int32_t last_enc_counter) {
  turn_pid_temp_.last_enc_counter = last_enc_counter;
}

void Robot::setLiftMotorLastENCCounter(int32_t last_enc_counter) {
  lift_pid_temp_.last_enc_counter = last_enc_counter;
}

void Robot::setLeftMotorSpeedwithoutPID() {
  // std::cout << "left_speed_without_PID_:" << left_speed_without_PID_ << std::endl;
  LeftMotor->setSpeedAndDir(static_cast<uint8_t>(abs(left_speed_without_PID_)), left_speed_without_PID_ > 0, left_speed_without_PID_ < 0);
}

void Robot::setRightMotorSpeedwithoutPID() {
  // std::cout << "right_speed_without_PID_:" << right_speed_without_PID_ << std::endl;
  RightMotor->setSpeedAndDir(static_cast<uint8_t>(abs(right_speed_without_PID_)), right_speed_without_PID_ > 0, right_speed_without_PID_ < 0);
}

void Robot::setTurnMotorSpeedwithoutPID() {
  TurnMotor->setSpeedAndDir(static_cast<uint8_t>(abs(turn_speed_without_PID_)), turn_speed_without_PID_ > 0, turn_speed_without_PID_ < 0);
}

void Robot::setLiftMotorSpeedwithoutPID() {
  LiftMotor->setSpeedAndDir(static_cast<uint8_t>(abs(lift_speed_without_PID_)), lift_speed_without_PID_ > 0, lift_speed_without_PID_ < 0);
}

