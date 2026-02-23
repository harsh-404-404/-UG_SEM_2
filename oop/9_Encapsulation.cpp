#include <iostream>

class BankAccount{
private:
    std::string holder;
    long accountNO;
    double balace;

    bool is_valid(double amt){
        return amt > 0;
    }
    BankAccount(std::string name,long n,double ibal){
        
    }

public:
    

};

