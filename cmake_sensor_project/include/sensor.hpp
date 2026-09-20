#pragma once
#include <string>
class Sensor
{
    public:
        Sensor(const std::string& name);
        ~Sensor();

        void printStatus() const;

    private:
        std::string name_;
        bool opened_;
};

