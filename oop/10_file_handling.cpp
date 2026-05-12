#include <iostream>
#include <cstring>
#include <fstream>

class Student{
public:
    int id {};
    char name[50] {};
    float marks {};
public:

    void input(){
        std::cout <<  "Enter Student's Id: ";
        std::cin >> id;
        std::cout << "Enter Students's name: ";
        std::cin >> name;
        std::cout << "Enter Students's marks: ";
        std::cin >> marks;
    }

    friend std::ostream& operator<<(std::ostream& op, const Student& st){
        std::cout << "ID: " << st.id <<  '\n'; 
        std::cout << "Name: " << st.name <<  '\n'; 
        std::cout << "Marks: " << st.marks <<  '\n';
        
        return op;
    }
};

void addStudent(){
    Student student{};
    student.input();
    
    std::ofstream fo {"studnet.txt", std::ios::app };
    fo.write((char*)&student, sizeof(student));
    fo.close();

    std::cout << "student recorded!!\n";
    // std::cout << student;  
}

void readStudent(){
    Student student;
    
    std::ifstream io {"studnet.txt"};
    while(io.read((char*)&student, sizeof(student))){
        std::cout << student;
    }
    io.close();
    //std::cout << student; J
}


int main(){
    addStudent();
    readStudent();
}