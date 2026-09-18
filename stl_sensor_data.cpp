#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

int main()
{
    //1.LiDAR distance data
    std::vector<double> distances{
        1.2,
        0.8,
        2.5,
        0.4,
        1.7
    };
    std::cout << "Original LiDAR distances: ";

    for (double distance : distances)
    {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    //2. Minimum and maximum distance
    double stop_threshold = 0.5;
    if (!distances.empty())
    {
    auto min_it =
        std::min_element(
            distances.begin(),
            distances.end()
        );
    std::cout
        << "Minimum distance: " << *min_it << " m" <<std::endl;

    if (*min_it < stop_threshold)
    {
        std::cout
            << "Robot command: STOP"
            << std::endl;
    }
    else
    {
        std::cout
            << "Robot command: SAFE"
            << std::endl;
    }
    }
    auto max_int = std::max_element(distances.begin(),distances.end());

    std::cout
        << "Maximum distance: " << *max_int << " m" << std::endl;
    
    //3.count close obstacles
    int close_count  = std::count_if(distances.begin(),distances.end(),[](double value)
    {
        return value < 1.0;
    });
    std::cout << "Measurements below 1.0 m: " << close_count << std::endl;

    //4.sort LiDAR data
    std::sort(
        distances.begin(),
        distances.end()
    );
    std::cout << "Sorted LiDAR data: ";
    for (double distance : distances)
    {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    //5.Sensor frequency table
    std::map<std::string,double> sensor_frequency{
        {"LiDAR", 10.0},
        {"Camera", 30.0},
        {"IMU", 200.0},
        {"GPS", 5.0}
    };
    std::cout << "\nSensor Frequencies:" <<std::endl;
    for (const auto& pair : sensor_frequency)
    {
        std::cout
            <<pair.first
            <<": "
            <<pair.second
            <<" HZ"
            <<std::endl;
    }

    //6.Sensor tatus table
    std::unordered_map<std::string,bool> sensor_status
    {
        {"LiDAR", true},
        {"Camera", true},
        {"IMU", false},
        {"GPS", true}
    };
    std::cout << "\nSensor Status:" << std::endl;
    for (const auto& pair : sensor_status)
    {
        std::cout
            << pair.first
            << ": "
            << (pair.second ? "ONELINE" : "OFFLINE")
            << std::endl;
    }

    //7.Query one sensoe
    std::string target_sensor = "IMU";
    auto status_it  = sensor_status.find(target_sensor);
    if (status_it != sensor_status.end())
    {
        std::cout
            <<"\n"
            << target_sensor
            << " is "
            << (status_it ->second ? "ONLINE" : "OFFLINE")
            << std::endl;
    }
    else
    {
        std::cout
            <<target_sensor
            <<" not found."
            <<std::endl;
    }
    return 0;
}