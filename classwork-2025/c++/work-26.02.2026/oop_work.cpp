#include <iostream>
#include <cstring>

const int max_marks{7};

class Student{
    char name[50];
    int marks[max_marks];
public:
    Student(char n[], int m[]){
        strcpy(name, n);
        for (int i{}; i < max_marks; i++){
            marks[i] = m[i];
        }
    }
    double AverMark(){
        double sum{};
        for(int i{}; i < max_marks; i++){
            sum+=marks[i];
        }
        return sum / max_marks;
    }
    void print(){
        std::cout << name;
        for(int i{}; i < max_marks; i++){
            std::cout << marks[i] << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    int marks[max_marks]{98,7,4,2,1,4,6};
    Student st("Elisey ", marks);
    st.print();
    std::cout << "average marks: " << st.AverMark();
    std::cout << st.name << '\n';

    return 0;
}