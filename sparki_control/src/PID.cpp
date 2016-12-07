//
// Created by carlh on 12/7/16.
//

#include <PID.h>

using namespace SparkiControl;

PID::PID(float KP, float KI, float KD) {
    this->KP = KP;
    this->KI = KI;
    this->KD = KD;
    I_error = 0;
}

float PID::update(float error) {
    float delta_error = this->error - error;
    this->error = error;
    I_error += error;
    delta_pos = (KP * error) + (KI * I_error) + (KD * delta_error);
    if(delta_pos < 0) return -delta_pos;
    return delta_pos;
}

void PID::reset() {
    I_error = 0;
}