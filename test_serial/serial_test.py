#!/usr/bin/env python3

import math
import time
import serial
from dataclasses import dataclass

@dataclass
class SerialStatus:
    """Class for different data given by the embedded system"""
    left_ref_speed: float
    right_ref_speed: float
    left_speed: float
    right_speed: float
    left_effort: float
    right_effort: float
    x_pos: float
    y_pos: float
    theta: float
    v: float
    w: float

def quaternion_from_euler(roll, pitch, yaw):
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)

    q = Quaternion()
    q.w = cy * cp * cr + sy * sp * sr
    q.x = cy * cp * sr - sy * sp * cr
    q.y = sy * cp * sr + cy * sp * cr
    q.z = sy * cp * cr - cy * sp * sr

    return q

def send_command(ser, linear: float, angular: float):
    command = f'{linear:.3f},{angular:.3f}\n'.encode('UTF-8')
    print(f'Sending command: "{command}"')
    ser.write(command)
    
    timeout = 0.1  # 100 ms timeout
    start_time = time.time()
    
    while ser.in_waiting == 0:
        if time.time() - start_time > timeout:
            print("No response, resending command")
            ser.write(command)
            start_time = time.time()
    
    try:
        res = ser.readline().decode('UTF-8')
        values = res.split(',')
        values = list(map(float, values))
    except (UnicodeDecodeError, ValueError) as e:
        print(f'Bad data: "{res}" - {e}')
        return None

    return SerialStatus(*values)

def main():
    port = 'COM7'  # Replace with the correct port for your system
    ser = serial.Serial(
        port=port,
        baudrate=115200,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
    )

    print(f'UART initialized on port {port}')

    try:
        while True:
            linear_speed = 1.0  # Example linear speed
            angular_speed = 0.5  # Example angular speed

            robot_state = send_command(ser, linear_speed, angular_speed)
            if robot_state is not None:
                print(f'Received: {robot_state}')
            
            time.sleep(0.04)  # 40ms delay

    except KeyboardInterrupt:
        print("Terminated by user")
    finally:
        ser.close()

if __name__ == '__main__':
    main()
