#include <iostream>
void changeSpeed(double& speed)
{
    speed = 0.0;
}
int main()
{
    double speed = 1.5;
    changeSpeed(speed);
    std::cout << speed << std::endl;
    return 0;
}
