#include <iostream>
#include <string>
#include <string_view>

class Student{

    int id {};
    std::string name;
    int marks[5];

    int tm {};
    float p {};
    char g {}; 

    public:
    Student(Student s){

    }
        void input();
        void cal();
        void print();

};
void Student::input(){

    std::cout << "Enter your Name: ";
    std::getline(std::cin >> std::ws,name);

    std::cout << "Enter your id: ";
    std::cin >> id;

}

void Student::cal(){
    for(int i = 0; i < 5; ++i){
        tm += marks[i]; 
    }
    p = (tm/5);
    if(p >= 90){
        g = 'A';
    }
    else if(p >= 80){
        g = 'B';
    }
    else if(p >= 70){
        g = 'C';
    }
    else if(p >= 60){
        g = 'D';
    }
    else if(p >= 50){
        g = 'E';
    }
    else{
        g = 'F';
    }
}

void Student::print(){

    std::cout << "Name :" << name << '\n';
    std::cout << "percentage: " << p << "%" << '\n';
    std::cout << "Grade: " << g << '\n';

}



int main(){

    int m[] = {1,2,3,4,5};
    Student s(m);
    Student ss 
    s.input();
    s.cal();
    s.print();

}