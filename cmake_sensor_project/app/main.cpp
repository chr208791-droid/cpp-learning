#include "sensor.hpp"

int main()
{
    Sensor lidar("LiDAR");
    Sensor camera("Camera");
    lidar.printStatus();
    camera.printStatus();
    return 0;
}