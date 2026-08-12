#include <iostream>
#include <cmath>

int main(){
    
    int x{ 1634 };

    int count{static_cast<int>(log10(x)) + 1};
    std::cout << count << '\n';
    int temp{ x };
    int sum{};

    while( temp != 0 ){
        sum += pow(temp % 10,count);
        temp /= 10;
    }
    if (sum == x){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
}