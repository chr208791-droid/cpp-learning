#include <iostream>
int main(){
    double distance[5] = {1.2,0.5,2.3,0.4,1.7};
    //std::cout << distance[1] << std::endl;
    //std::cout << distance[4] << std::endl;
    for (int i=0; i<5; i++)
    {
        if(distance[i]<0.5)
        {
            std::cout << "Obstacle detected" << std::endl;
        }
        std::cout << distance[i] << std::endl;
    }
    return 0;
}