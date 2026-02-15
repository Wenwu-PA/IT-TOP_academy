#include <iostream>

struct Car {
    double length;
    double clearance;
    double engine_volume;
    double engine_power;
    double wheel_diameter;
    char color[20];
    char transmission_type[20];
};

void setCarValues(Car* car, double len, double clr, double vol, double pow, double diam, const char* col, const char* trans) {
    car->length = len;
    car->clearance = clr;
    car->engine_volume = vol;
    car->engine_power = pow;
    car->wheel_diameter = diam;
    
    int i = 0;
    while (col[i] != '\0' && i < 19) {
        car->color[i] = col[i];
        i++;
    }
    car->color[i] = '\0';
    
    i = 0;
    while (trans[i] != '\0' && i < 19) {
        car->transmission_type[i] = trans[i];
        i++;
    }
    car->transmission_type[i] = '\0';
}

void displayCarValues(const Car* car) {
    std::cout << "Length: " << car->length << std::endl;
    std::cout << "Clearance: " << car->clearance << std::endl;
    std::cout << "Engine Volume: " << car->engine_volume << std::endl;
    std::cout << "Engine Power: " << car->engine_power << std::endl;
    std::cout << "Wheel Diameter: " << car->wheel_diameter << std::endl;
    std::cout << "Color: " << car->color << std::endl;
    std::cout << "Transmission Type: " << car->transmission_type << std::endl;
}

int findCarByColor(const Car* cars, int count, const char* color) {
    for (int i = 0; i < count; i++) {
        bool match = true;
        for (int j = 0; color[j] != '\0' || cars[i].color[j] != '\0'; j++) {
            if (color[j] != cars[i].color[j]) {
                match = false;
                break;
            }
            if (color[j] == '\0') break;
        }
        if (match) return i;
    }
    return -1;
}

int main() {
    Car car1;
    setCarValues(&car1, 4.5, 0.15, 1.6, 120.0, 17.0, "red", "manual");
    displayCarValues(&car1);
    
    Car cars[2];
    setCarValues(&cars[0], 5.0, 0.18, 2.0, 180.0, 18.0, "blue", "automatic");
    setCarValues(&cars[1], 4.2, 0.12, 1.4, 100.0, 16.0, "red", "automatic");
    
    int result = findCarByColor(cars, 2, "red");
    if (result != -1) {
        std::cout << "Found red car at index " << result << std::endl;
    }
    
    return 0;
}