#include <iostream>
#include <vector>
int main()
{
    std::vector<double> distances = {1.2,0.8,2.5};
    distances.push_back(1.5);
    std::cout << distances.size() << std::endl;
    for(double distance: distances)
    {
        std::cout << distance << std::endl;
    }
    return 0;
}