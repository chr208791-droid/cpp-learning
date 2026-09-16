#include <iostream>
#include <string>
int main()
{
    /*std::string robot_name = "mobile_robot";
    std::string status = "SAFE";
    std::cout << robot_name << std::endl;
    std::cout << status << std::endl;
    std::cout << "length:" << robot_name.size() << std::endl;
    return 0;*/
    std::string robot = "Robot";
    std::string id = "_01";
    std::string name = robot + id;
    //std::cout << name << std::endl;
    if(name == "Robot_01")
    {
        std::cout << "True" << std::endl;
    }
    return 0;

}