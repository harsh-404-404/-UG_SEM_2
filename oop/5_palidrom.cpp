#include <iostream>

int main(){

    int x{ 111 };
    int rev{};
    int temp{ x };
    while(temp != 0){
        rev = (temp % 10) + rev*10;
        temp /= 10;
    }
    std::cout << ((rev == x) ? "Yes" : "NO") << "\n";

}