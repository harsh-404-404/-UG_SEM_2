#include <iostream>

using namespace std;

int main(){

    int x{ 12345 };
    while(x != 0){
        cout<< x % 10;
        x /= 10;   
    }

}