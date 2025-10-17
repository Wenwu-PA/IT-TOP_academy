#include <iostream>

int main()
{
    int distance{}, 
    int minutes{}, 
    int seconds{};
    double time{}, 
    double speed{};

    std::cout << "Enter distance (meters): ";
    std::cin >> distance;

    std::cout << "Enter time (minutes.seconds): ";
    std::cin >> time;

    minutes = time;
    seconds = (time - minutes) * 100;
    time = (minutes * 60) + seconds;

    speed = distance / time*3.6;

    std::cout << "Distance: " << distance << " m" << "\n";
    std::cout << "Time: " << time << " seconds" << "\n";
    std::cout << "Speed: " << speed << " km/h" << "\n";

    return 0;
}