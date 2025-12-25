#include <iostream>
enum weekdays{mon = 1,tue,wen,thu,fri,sat,sun};
const char* getweekdays(weekdays day);

int main (){

    weekdays day{mon};

    enum {male,female} sex {female};

    if (day==thu){
        std::cout << "Сегодня - четверг" << "\n";  
    }
    std::cout << sex << '\n';
    std::cout << getweekdays(day) << "\n";

    day - (weekdays)5;
    std::cout << getweekdays(day) << "\n";

    return 0;
}

const char* getweekdays(weekdays day){
    switch (day){
        case mon: return "monday";
        case tue: return "tuesday";
        case wen: return "wensday";
        case thu: return "thuesday";
        case fri: return "friday";
        case sat: return "saturday";
        case sun: return "sunday";
        default: return "error";
    }
}