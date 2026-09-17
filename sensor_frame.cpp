#include <iostream>
#include <string>
#include <vector>

class Sensor{
    public:
        Sensor(const std::string& name)
            : name_(name),
              opened_(true)
        {
           std::cout
            << "[OPEN] "
            << name_
            << std::endl;
        }
        ~Sensor()
        {
             if (opened_)
        {
            std::cout
                << "[CLOSE] "
                << name_
                << std::endl;
        }
    }

    void printStatus() const
    {
        std::cout
            << "Sensor: "
            << name_
            << std::endl;

        std::cout
            << "Opened: "
            << opened_
            << std::endl;
        }
    private:
        std::string name_;
        bool opened_;
};
class Frame
{
private:
    int id_;
    std::vector<double> data_;
public:
    Frame(int id,const std::vector<double>& data)
        :id_(id),
         data_(data)
    {
        std::cout
            << "[Frame] "
            << id_
            << " constructed."
            << std::endl;
    }     


    ~Frame()
    {
        std::cout
            << "[Frame] "
            << id_
            << " destroyed."
            << std::endl;
    }
    void print() const
    {
         std::cout
            << "Frame ID: "
            << id_
            << std::endl;

        std::cout
            << "Measurement count: "
            << data_.size()
            << std::endl;
    }
    double minDistance() const
    {
    double min_value = data_[0];

    for (double value : data_)
    {
        if (value < min_value)
        {
            min_value = value;
        }
    }

    return min_value;
    }
};
int main()
{
    /*std::cout << "Program start." << std::endl;
    Sensor lidar;
    std::cout << "Program running." << std::endl;
    std::cout << "Program start." << std::endl;
    {
        std::cout << "Enter scope." << std::endl;

        Sensor lidar;

        std::cout << "Sensor is working." << std::endl;
    }
    std::cout << "Leave scope." << std::endl;
    return 0;*/
    //Sensor lidar("LiDAR");
    std::cout << "Program start." << std::endl;

    Sensor lidar("LiDAR");

    lidar.printStatus();

    {
        std::vector<double> distances{
            1.2,
            0.8,
            2.5,
            0.4,
            1.7
        };

        Frame frame(1, distances);

        frame.print();

        std::cout
            << "Minimum distance: "
            << frame.minDistance()
            << " m"
            << std::endl;
    }

    std::cout
        << "Frame processing finished."
        << std::endl;

    return 0;
 
}
