/*
 * dc_motor.cpp
 *
 *  Created on: Jun 30, 2024
 *      Author: dat
 */


#include "dc_motor.h"

DCMotor::DCMotor(TIM_HandleTypeDef *pwm_tim, uint32_t fwd_chan, uint32_t rev_chan)
:_pwm_tim(pwm_tim), _fwd_chan(fwd_chan), _rev_chan(rev_chan)
{
	HAL_TIM_PWM_Start(_pwm_tim, _fwd_chan);
	HAL_TIM_PWM_Start(_pwm_tim, _rev_chan);

}

void DCMotor::write_int16(int16_t pwm)
{
    if(pwm < 0)
    {
    	__HAL_TIM_SET_COMPARE(DCMotor::_pwm_tim, DCMotor::_rev_chan, pwm);
    	__HAL_TIM_SET_COMPARE(DCMotor::_pwm_tim, DCMotor::_fwd_chan, 0);
    } else
    {
    	__HAL_TIM_SET_COMPARE(DCMotor::_pwm_tim, DCMotor::_fwd_chan, pwm);
    	__HAL_TIM_SET_COMPARE(DCMotor::_pwm_tim, DCMotor::_rev_chan, 0);
    }

}

void DCMotor::write(float duty_cycle)
{
    if(duty_cycle > 1.0f) duty_cycle = 1.0f;
    if(duty_cycle < -1.0f) duty_cycle = -1.0f;
    write_int16((int16_t)(duty_cycle * TOP));
}

