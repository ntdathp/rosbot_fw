/*
 * robot.h
 *
 *  Created on: Jun 30, 2024
 *      Author: dat
 */

#ifndef CPP_ROBOT_H_
#define CPP_ROBOT_H_

#include "pid_controller.h"
#include "dc_motor.h"

#define L_MOTOR_MIN_SPEED -1.0f
#define L_MOTOR_MAX_SPEED 1.0f
#define R_MOTOR_MIN_SPEED -1.0f
#define R_MOTOR_MAX_SPEED 1.0f
#define ROBOT_MOTOR_PPR 3960.0f
#define ROBOT_WHEEL_RADIUS 0.048f
#define ROBOT_WHEEL_SEPARATION 0.295f
#define ROBOT_MAX_LINEAR_M_S 0.5
#define ROBOT_MIN_LINEAR_M_S (-0.5)
#define ROBOT_MAX_ANGULAR_R_S 2.0
#define ROBOT_MIN_ANGULAR_R_S (-2.0)

struct MotorPins
{
	TIM_HandleTypeDef* _pwm_tim;
    uint32_t _fwd_chan;
	uint32_t _rev_chan;
};

struct RobotPins
{
    MotorPins left;
    MotorPins right;
};

struct RobotState
{
    int32_t l_ticks;
    int32_t r_ticks;
    float l_position;
    float r_position;
    float l_speed;
    float r_speed;
    float l_effort;
    float r_effort;
    float l_ref_speed;
    float r_ref_speed;
};

struct RobotOdometry
{
    float x_pos;
    float y_pos;
    float theta;
    float v;
    float w;
};

class Robot{
public:
    Robot(
            float kp,
            float kd,
            float ki,
            uint32_t sample_time_ms,
            RobotPins pins
            );
    void start();
    void setWheels(float left_speed, float right_speed);
    void setUnicycle(float v, float w);
    RobotState getState();
    RobotOdometry getOdometry();
    void setPidTunings(float kp, float kd, float ki);
    void updatePid(uint32_t l_encoder_ticks, uint32_t r_encoder_ticks);

private:
    float _kp;
    float _kd;
    float _ki;
    float _pid_rate;
    uint32_t _sample_time_ms;
    float _l_input;
    float _l_output;
    float _l_setpoint;
    float _r_input;
    float _r_output;
    float _r_setpoint;
    float _linear;
    float _angular;

    DCMotor _l_motor;
    DCMotor _r_motor;
    PID _l_pid;
    PID _r_pid;
    RobotState _state;
    RobotOdometry _odom;

    void controlLoop();
    void updateOdometry(int32_t dl_ticks, int32_t dr_ticks);
    void initPins();
};



#endif /* CPP_ROBOT_H_ */
