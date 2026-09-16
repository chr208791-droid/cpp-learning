#include <iostream>
#include <vector>

std::size_t countMeasurements(const std::vector<double>& data)
{
    return data.size();
}

double findMinimum(const std::vector<double>& data)
{
    double minimum = data[0];

    for (std::size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] < minimum)
        {
            minimum = data[i];
        }
    }

    return minimum;
}

double findAverage(const std::vector<double>& data)
{
    double sum = 0.0;

    for (std::size_t i = 0; i < data.size(); ++i)
    {
        sum = sum + data[i];
    }

    return sum / data.size();
}

bool hasObstacle(const std::vector<double>& data)
{
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] < 0.5)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<double> distances = {1.2, 0.8, 2.5, 0.4, 1.7};

    std::cout << "Measurements: "
              << countMeasurements(distances)
              << std::endl;

    std::cout << "Minimum distance: "
              << findMinimum(distances)
              << " m"
              << std::endl;

    std::cout << "Average distance: "
              << findAverage(distances)
              << " m"
              << std::endl;

    if (hasObstacle(distances))
    {
        std::cout << "Status: STOP" << std::endl;
    }
    else
    {
        std::cout << "Status: SAFE" << std::endl;
    }

    return 0;
}