#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
#include <optional>

class Account{
public:
    enum class TypesOfAccout{
        savings,
        current,
        salary,
    };

private:

    std::string m_name {};
    const long m_accountNumber {};
    double m_balance {};
    TypesOfAccout m_type{};
    int m_pin{};

    bool is_valid(double i){
        return i > 0.0;
    }


    const std::optional<TypesOfAccout> stringToType (const std::string_view string) const {
        using enum TypesOfAccout;
        if(string == "savings") return savings;
        if(string == "current") return current;
        if(string == "salary") return salary;
        return {};
    }
    

public:
    Account(std::string_view name,long accountNumber,double balance,int pin,TypesOfAccout type = TypesOfAccout::current) : 
        m_name { name }, m_accountNumber { accountNumber }, m_balance { balance }, m_pin { pin }, m_type { type } 
    {//temprory error cheking because i don't know how to do proper input checks with member list initializer 
        assert(is_valid(balance) && "Invalid balance input");
    }

    std::string_view getName() const { return m_name ;}           //getter for name
    void set_name(const std::string& new_name) { m_name = new_name; }   //setter for name
    
    std::string_view getType() const { return typeToString(m_type); }              //getter for account type
    void setType(const std::string_view new_type){                                      //setter for account type
        std::optional<TypesOfAccout> match { stringToType(new_type) };
        if(!match){
            std::cerr << "Invalied Account type!!";
            return;
        }
        m_type = *match;
        return;
    }
    const std::string_view typeToString (TypesOfAccout type) const {
        using enum TypesOfAccout;
        switch (type){
        case savings:  return "savings";
        case current: return "current";
        case salary: return "salary";
        default: return "???";
        }
    };

    const long getAccountNumber() const { return m_accountNumber; } //getter for account number

    void deposite(double add,int pin){
        assert(is_valid(add) && "Invalid deposite ammount input !!");
        assert((pin == m_pin) && "Incorrect pin");         
        m_balance += add;
    }
    void withdraw(double remove,int pin){
        assert((is_valid(remove) && (remove < m_balance)) && "Invalid withdraw ammount !!");  
        assert((pin == m_pin) && "Incorrect pin");             
        m_balance -= remove;  
    }
    const double getBalance() const { return m_balance; }

};


std::ostream& operator<<(std::ostream& op,const Account& obj){
    return op << "Name: " << obj.getName() << "\nAccount Number: " << obj.getAccountNumber() << "\nAccount Type: " << obj.getType() << "\nBalance: " << obj.getBalance() << '\n';  
    // removed  i don't know how to use this friend thingy with classes 
}

int main(){
    Account joe {"Joe", 2855, 1000.99,2007};
    joe.deposite(0.01,2007);
    joe.withdraw(1000,2007);
    joe.setType("salary");
    std::cout<< joe;
}