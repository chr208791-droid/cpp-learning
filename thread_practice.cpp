#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<double> data_queue;
std::mutex queue_mutex;
std::condition_variable queue_cv;
bool producer_done = false;
void producer()
{
    double sensor_data[] = {
        1.2,
        0.8,
        0.4,
        2.1,
        1.5
    };
    for (double value : sensor_data)
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)
        );
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            data_queue.push(value);
        }
        std::cout
        << "[Producer] LiDAR: "
        << value
        << " m"
        << std::endl;

        queue_cv.notify_one();
    }
    
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        producer_done = true;

    }
    queue_cv.notify_one();
    
}
void consumer()
{
    while(true)
    {
        double value = 0.0;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            queue_cv.wait(
                    lock,
                    []
                    {
                        return !data_queue.empty() || producer_done;
                    }                
            );
            if (data_queue.empty() && producer_done)
            {
                break;
            }
            value = data_queue.front();
            data_queue.pop();
        }
        std::cout
            << "[Consumer] Processing: "
            << value
            << " m"
            << std::endl;
    }
    std::cout
        << "[Consumer] Finished."
        << std::endl;
    
}
int main()
{
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    std::cout
        << "Pipeline finished."
        << std::endl;

    return 0;
}

/*double sensor_data = 0.0;
bool data_ready = false;

std::mutex data_mutex;
std::condition_variable data_cv;

void producer()
{
    std::this_thread::sleep_for(
        std::chrono::seconds(2)
    );

    {
        std::lock_guard<std::mutex> lock(data_mutex);

        sensor_data = 0.42;
        data_ready = true;
    }

    std::cout
        << "Producer: new LiDAR data."
        << std::endl;

    data_cv.notify_one();
}

void consumer()
{
    std::unique_lock<std::mutex> lock(data_mutex);

    data_cv.wait(
        lock,
        []
        {
            return data_ready;
        }
    );

    std::cout
        << "Consumer: processing data = "
        << sensor_data
        << std::endl;
}

int main()
{
    std::thread consumer_thread(consumer);
    std::thread producer_thread(producer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
void sensorTask(const std::string& name, int delay_ms)
{
    
    std::cout 
        << name
        << " started." 
        << std::endl;

    std::this_thread::sleep_for(
            std::chrono::milliseconds(delay_ms)
    );
    std::cout
        << name 
        << " finished."
        << std::endl;
}

int main()
{
    std::thread lidar_thread(sensorTask,"LiDAR",1000);
    std::thread camrea_thread(sensorTask,"Camera",1500);
    std::thread imu_thread(sensorTask,"IMU",500);
    lidar_thread.join(); 
    camrea_thread.join();
    imu_thread.join();
    std::cout << "All sensors finished." << std::endl;
    return 0;
}
int processed_frames = 0;
std::mutex frame_mutex;
void sensorTask(const std::string& sensor_name,int frame_count)
{
    for(int i = 0; i<frame_count; i++)
    {
        std::lock_guard<std::mutex> lock(frame_mutex);
        ++processed_frames;
    }
    std::cout
        << sensor_name
        << " finished."
        << std::endl;
}
int main()
{
    std::thread lidar_thread(sensorTask,"LiDAR",50000);
    std::thread camera_thread(sensorTask,"Camera",50000);
    std::thread imu_thread(sensorTask,"IMU",50000);
    lidar_thread.join();
    camera_thread.join();
    imu_thread.join();
    std::cout
        << "Total received frames: "
        << processed_frames
        << std::endl;

    return 0;
}*/