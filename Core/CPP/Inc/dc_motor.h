/*
 * dc_motor.h
 *
 *  Created on: Jun 30, 2024
 *      Author: dat
 */

#ifndef CPP_DC_MOTOR_H_
#define CPP_DC_MOTOR_H_

#include <stdint.h>
#include "tim.h"

#define TOP 99

typedef unsigned int uint;

class DCMotor {
public:
    DCMotor(TIM_HandleTypeDef *pwm_tim, uint32_t fwd_chan, uint32_t rev_chan);
    void write_int16(int16_t pwm);
    void write(float duty_cycle);

private:
    TIM_HandleTypeDef* _pwm_tim;
	uint32_t _fwd_chan;
	uint32_t _rev_chan;
};

#endif /* CPP_DC_MOTOR_H_ */
