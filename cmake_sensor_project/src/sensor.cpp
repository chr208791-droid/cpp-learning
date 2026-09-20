#include "sensor.hpp"
#include <iostream>
Sensor::Sensor(const std::string& name)
    : name_(name),
     opened_(true)
{
    std::cout
        << "[OPEN] "
        << name_
        << std::endl;
}
Sensor:: ~Sensor()
{
    if(opened_)
    {
        std::cout
            << "[CLOSE] "
            << name_
            <<std::endl;
    }
}
void Sensor::printStatus() const
{
    std::cout
        << name_
        << ": "
        << (opened_ ? "ONLINE" : "OFFLINE")
        <<std::endl;
}