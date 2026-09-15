#include <iostream>
void checkObstacle(double distance)
    {
        if(distance < 0.5)
        {
            std::cout << "stop" << std::endl;
        }
        else
        {
            std::cout << "safe" << std::endl;
        }
    }
int main(){
   /*int v = 10;
    double distance = 1.25;
    bool datected = true;
    std::string robot_name="robot1";
    std::cout<<"机器人速度："<< v << std:: endl;
    std::cout<<"障碍物距离："<< distance << std::endl;
    std::cout<<"电池电量："<< datected << std::endl;
    std::cout<<"机器人型号："<< robot_name <<std::endl;
    if (distance < 0.5)
    {
        std::cout << "stop" << std::endl;
    }
    else if (distance < 1.5)
    {
        std::cout << "slow" << std::endl;
    }
    else
    {
        std::cout << "safe" << std::endl;
    }
        for (int i = 0; i < 10; ++i)
    {
        std::cout <<"Frame:" << i << std::endl;
    }
    int count = 0;
    while(count < 5)
    {
        std::cout << count << std::endl;
        count++;
    }*/ 
    double distance;
    std::cout <<"请输入障碍物距离：";
    std::cin >> distance;
    checkObstacle(distance);
    
}
