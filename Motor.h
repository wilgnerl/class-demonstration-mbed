#ifndef MBED_MOTOR_H
#define MBED_MOTOR_H
 
#include "mbed.h"
 
class Motor{
    public:
       Motor(PinName pin1, PinName pin2, PinName pin3, PinName pin4);
        void gira_motor_sentido_horario(int tempo);
        void gira_motor_sentido_antihorario(int tempo);
        void stop();
    private:
        BusOut bus;
}; 
 
 
#endif
