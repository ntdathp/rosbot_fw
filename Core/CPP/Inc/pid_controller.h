/*
 * pid_controller.h
 *
 *  Created on: Jun 30, 2024
 *      Author: dat
 */

#ifndef CPP_PID_CONTROLLER_H_
#define CPP_PID_CONTROLLER_H_

#include "stdint.h"
#include "math.h"

class PID {
public:
    PID(float* input, float* output, float* setpoint, float kp, float ki, float kd, uint32_t sample_time_ms);
    void compute(void);
    void set_output_limits(float min, float max);
    void set_gains(float kp, float ki, float kd);
    void set_sample_time(uint32_t new_sample_time_ms);

private:
    uint32_t _sample_time_ms;
    uint32_t _last_time;
    float _kp;
    float _kd;
    float _ki;

    float* _my_input;
    float* _my_output;
    float* _my_setpoint;
    float _out_min;
    float _out_max;
    float _out_sum;
    float _err_sum;
    float _last_err;
    float _i_term;
    float _last_input;

};



#endif /* CPP_PID_CONTROLLER_H_ */
