//
// Created by troy on 12/13/16.
//

#pragma once

#ifndef SIMPLE_MOTION_TRAPEZOID_INTERPOLATION_H
#define SIMPLE_MOTION_TRAPEZOID_INTERPOLATION_H

#include "interpolation.h"
#include "global_variables.h"

class TrapezoidInterpolation final : public Interpolation {
private:
    InterpolationState interpolate_state;
    std::string type;
    enum {
        kIdle, kAcceleration, kLinear, kDeceleration, kEnd
    } state = kIdle;

    double t0, t1, t2, t3;
    AxisStatus s0, s1, s2, s3;

public:
    double position;
    double velocity;
    double acceleration;
    double deceleration;
    AxisStatus *axis;

    TrapezoidInterpolation();

    virtual ~TrapezoidInterpolation();

    virtual InterpolationState check(void);

    /**
     * @brief Start Interpolation, it'll check the validation of the command
     * @param start_time_ns t0 in nanosecond
     * @return current interpolating status, only kError/kRunning
     */
    virtual InterpolationState start(const RTIME start_time_ns);

    /**
     * @brief interpolate once
     * @param curr_time_ns t in nanosecond
     * @return current interpolating status
     */
    virtual InterpolationState move(const RTIME curr_time_ns);

    /**
     * @brief return current interpolating status
     * @return interpolating status
     */
    virtual InterpolationState get_status(void);

    virtual std::string get_type(void);
};


#endif //SIMPLE_MOTION_TRAPEZOID_INTERPOLATION_H
