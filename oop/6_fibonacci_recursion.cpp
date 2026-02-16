#include <iostream>

void printfibo(size_t n, size_t first,size_t secound){

    if (n == 0){
        return;
    }
    size_t third { first + secound };
    std::cout << third << " ";
    printfibo(n-1,secound,third);  

}

void fibonacci(size_t n){

    if (n < 3){
        std::cout << "Minimum number of terms is 3!!";
    }
    else{
        std::cout << "Febonacci Series" << '\n';
        std::cout << "0 1 ";
        printfibo(n - 2, 0 , 1);
    }

}


int main(){

    size_t n{};
    std::cout << "Enter number of terms: ";
    std::cin >> n;
    
    fibonacci(n);

}