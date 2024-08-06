#pragma once
// 开关打开角度
#define SWITCHOPEN 0.15
// 开关关闭角度
#define SWITCHCLOSE 0.09

// 左边播种
#define SEEDLEFT 0.23
// 右边播种
#define SEEDRIGHT 0.181
// 中间
#define SEEDMIDDLE 0.2
// 左右切换时间间隔
#define SEEDTIMEINTERVAL 10
// 播种停顿时间
#define SEEDSTOPTERVAL 10
// 装载右仓库的种子
#define LOADONTHERIGHT 0.115
// 装载左仓库的种子
#define LOADONTHELEFT 0.18
// 装载左右时间间隔
#define LOADONTIMEINTERVAL 5


// 搅拌舵机在中间位置
#define MIXINGMIDDLE 0.148
// 播右边种子的最高处
#define PlANTRIGHTUP 0.18
// 播右边种子的最低处
#define PlANTRIGHTDOWN 0.15
// 播边左边种子的最高处
#define PLANTLEFTUP 0.110
// 播边左边种子的最低处
#define PLANTLEFTDOWN 0.145
// 拨动时间间隔
#define MIXINGTIMEINTERVAL 25
// 搅拌停顿时间
#define MIXINGSTOPTIME 10
// 拨动计数值
#define MIXINGCOUNTER 10

#define SEEDLIFTPWM 0
#define SEEDMOTORSPEED -10


struct PIDParams {
    double kp;
    double ki;
    double kd;
};


// PID参数
#define LEFTMOTORPID  {0.2, 0.005, 0}
#define RIGHTMOTORPID {0.2, 0.005, 0}
#define TURNMOTORPID  {0.2, 0.005, 0}
#define LIFTMOTORPID  {0.2, 0.005, 0}

struct PIDOutputLimits {
    double min;
    double max;
};
#define LEFTMOTOROUTPUTLIMITS  {-100, 100}
#define RIGHTMOTOROUTPUTLIMITS {-100, 100}
#define TURNMOTOROUTPUTLIMITS  {-100, 100}
#define LIFTMOTOROUTPUTLIMITS  {-100, 100}

#define PIDDT 0.02


