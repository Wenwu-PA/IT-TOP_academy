#include <iostream>
#include <iomanip> // для манипуляторов вывода
#include <ctime>

//работа с вещественными числами

// int main(){
//     std::cout << std::setprecision(170) << 0.1 + 0.2 << "\n";
//     if (0.1 + 0.2 == 0.3)
//         std::cout << "true";
//     else
//         std::cout << "false" ;

//     return 0;
// }


// int main()
// {
//     std::srand(std::time(0));
//     const int secret{std::rand() % 100 + 1};
//     std::cout << RAND_MAX << "\n";
//     int num{std::rand()};
//     const int secret{std::rand()};
//     const int maxAttempts{5};
//     int number{};
//     int attempts{1};
//     do
//     {
//         std::cout << "Guess the number: ";
//         std::cin >> number;

//         if (number < secret)
//         {
//             std::cout << "Secret number is bigger\n";
//         }
//         else if (number > secret)
//         {
//             std::cout << "Secret number is smaller\n";
//         }
//         else
//         {
//             std::cout << "You won!\n"
//                       << "It took you " << attempts << " tries\n";
//             return 0;
//         }
//         attempts++;

//     } while(attempts < maxAttempts);
//     std::cout << "Games over!";

//     return 0;
// }

// int main(){
//     int x{};
//     int res{};

//     std::cout << "Input time: ";
//     std::cin >> x;

//     for (int i{}; i <= x; i++)
//     {
//         res+=i;  
//     }
//     std::cout << "output: " << res << "\n";
//     return 0;
// }

int main(){
    int res{};
    int max{};
    int min{};
    char stopwhile{'n'};
    do {
        int num{};
        std::cout << "input: ";
        std::cin >> num;

        if (num > max){
            max = num;
        }
        else if(num < min){
            min = num;
        }
        std::cout << "stop?";
        std::cin >> stopwhile;
    }
    while(stopwhile != 'y');

    std::cout << "max: " << max << '\n';
    std::cout << "min: " << min << '\n';

    return 0;
}