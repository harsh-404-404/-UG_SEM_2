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
    Student(int marks[5]){
        
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

    for(int i = 0; i < 5; ++i){
        std::cout << "Enter marks of subject " << i + 1 << ": ";
        std::cin >> marks[i];
    }
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
    std::cout << "persentage: " << p << "%" << '\n';
    std::cout << "Grade: " << g << '\n';

}



int main(){

    Student s;
    s.input();
    s.cal();
    s.print();

}