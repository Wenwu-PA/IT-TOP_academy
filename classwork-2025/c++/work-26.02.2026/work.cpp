#include <iostream>
#include <cstring>
const int max_marks{7};

struct student{
    char name[50];
    int marks[max_marks];

};


void create_student(student& student,char name[], int m[]){
    strcpy(student.name, name);
    for (int i{}; i < max_marks; i++){
        student.marks[i] = m[i];
    }

}

double AverMark(student s){
    double sum{};
    for(int i{}; i < max_marks; i++){
        sum+=s.marks[i];
    }
    return sum / max_marks;
}
void print(student s){
    std::cout << s.name;
    for(int i{}; i < max_marks; i++){
        std::cout << s.marks[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    student st;
    int marks[max_marks]{98,7,4,2,1,4,6};
    create_student(st,"Elisey ", marks);
    print(st);
    std::cout << "average marks: " << AverMark(st);

    return 0;
}