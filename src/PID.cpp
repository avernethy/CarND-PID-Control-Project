#include "PID.h"
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    p_error = 0;
    i_error = 0;
    d_error = 0;
    prev_error = 0;
    accum_error = 0;

    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
}

void PID::UpdateError(double cte) {
    accum_error = accum_error + cte;
    p_error = cte * Kp;
    i_error = accum_error * Ki;
    d_error = (cte-prev_error) * Kd;
    prev_error = cte;
}

double PID::TotalError() {
    //std::cout<<"p_error: "<< p_error<<std::endl;
   double total_error = p_error + i_error + d_error;
   
   return -total_error;
}
