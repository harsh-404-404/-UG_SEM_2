#include <iostream>
#include <cmath>

int main(){

    int x{ 123456 };
    std::cout << static_cast<int>(log10(x)) + 1 << '\n';

}