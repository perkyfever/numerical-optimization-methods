#pragma once

#include <array>
#include <cmath>

class Density;
class AirSpeed;

class Pressure {
public:
    Pressure(double p0, double t0);
    double operator()(double height);

private:
    friend class Density;
    std::array<double, 4> p;
    std::array<double, 5> t;
};

class Density {
public:
    Density(Pressure p) : pressure(p){};
    double operator()(double height);

private:
    friend class AirSpeed;
    Pressure pressure;
};

class AirSpeed {
public:
    AirSpeed(Density d) : density(d){};
    double operator()(double height);

private:
    Density density;
};

class DragCoef {
public:
    DragCoef(){};
    double operator()(double mach);

private:
    double step = 0.1;
    std::array<double, 26> coefs = {
        0.00,  // 0.0
        0.10,  // 0.1
        0.10,  // 0.2
        0.10,  // 0.3
        0.10,  // 0.4
        0.10,  // 0.5
        0.10,  // 0.6
        0.11,  // 0.7
        0.12,  // 0.8
        0.17,  // 0.9
        0.38,  // 1.0
        0.34,  // 1.1
        0.33,  // 1.2
        0.32,  // 1.3
        0.31,  // 1.4
        0.30,  // 1.5
        0.30,  // 1.6
        0.29,  // 1.7
        0.27,  // 1.8
        0.26,  // 1.9
        0.25,  // 2.0
        0.24,  // 2.1
        0.23,  // 2.2
        0.22,  // 2.3
        0.21,  // 2.4
        0.20,  // 2.5
    };
};

class AerodynamicDragForce {
public:
    AerodynamicDragForce(DragCoef dragCoef, Density d) : cd(dragCoef), density(d){};
    double operator()(double mach, double y, double velocity, double s);

private:
    DragCoef cd;
    Density density;
};

void nextState(
    AerodynamicDragForce q,
    double mass,
    double mach,
    double s,
    const std::array<double, 4> &u,
    std::array<double, 4> &result
);

class RHS_Velocity {
private:
    double m_p0;
    double m_t0;
    double m_mass;
    double m_diameter;
    double m_s;

public:
    constexpr static int N = 4;
    RHS_Velocity(double a_p0, double a_t0, double a_mass, double a_diameter, double a_s)
        : m_p0(a_p0), m_t0(a_t0), m_mass(a_mass), m_diameter(a_diameter), m_s(a_s){};
    void
    operator()(double a_t, std::array<double, 4> &a_v, std::array<double, 4> &result);
};