#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "robot.h"
#include "user_define.h"

char in_buffer[100];
uint16_t char_idx = 0;
uint8_t urx = 0;

volatile int32_t encoder1_ticks = 0;
volatile int32_t encoder2_ticks = 0;

RobotPins robot_pins = {
        {
        		&PWM_TIMER,
				TIM_CHANNEL_1,
				TIM_CHANNEL_2
        },{
        		&PWM_TIMER,
        		TIM_CHANNEL_4,
        		TIM_CHANNEL_3
        }
};

float kp1 = 0.04;
float ki1 = 0.1;
float kd1 = 0.0;

float linear = 0.0;
float angular = 0;

char* ch_ptr;
char* ch_ptr2;
char* ch_ptr3;


uint32_t sample_time_ms = 20;

Robot robot(
        kp1, kd1, ki1,
        sample_time_ms,
        robot_pins
        );


void ReadEncoder(){
	int16_t et1 = ECODER_TIMER1.Instance->CNT;
	int16_t et2 = ECODER_TIMER2.Instance->CNT;

	encoder1_ticks += (et1);
	encoder2_ticks += (-et2);

	ECODER_TIMER1.Instance->CNT = 0;
	ECODER_TIMER2.Instance->CNT = 0;
}



void printState(float v, float w, RobotState state, RobotOdometry odometry)
{
    printf(
            // diff setpoint,wheel setpoint, speed
            "%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n",
            state.l_ref_speed, state.r_ref_speed, state.l_speed, state.r_speed, state.l_effort, state.r_effort,
            odometry.x_pos, odometry.y_pos, odometry.theta, odometry.v, odometry.w
            );
}


void CppMain(){
	while(1)
	{
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == UART_COM_INSTANCE)
    {
        if (char_idx > 11)
        {
            // Clear the buffer and reset char_idx if the index exceeds 11
            memset(in_buffer, 0, sizeof(in_buffer));
            char_idx = 0;
        }
        else
        {
            if (urx != '\n')
            {
                in_buffer[char_idx] = urx;
                char_idx++;
            }
            else
            {
                in_buffer[char_idx] = 0; // Null-terminate the string
                char_idx = 0; // Reset the index
                linear = strtof(in_buffer, &ch_ptr);
                angular = strtof(ch_ptr + 1, &ch_ptr2);
                printState(linear, angular, robot.getState(), robot.getOdometry());
            }
        }
    }
    HAL_UART_Receive_IT(&UART_COM, &urx, 1);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == INTERUPT_TIMER_INSTANCE)
  {
	  ReadEncoder();
	  robot.setUnicycle(linear, angular);
	  robot.updatePid(encoder1_ticks, encoder2_ticks);
  }
}

