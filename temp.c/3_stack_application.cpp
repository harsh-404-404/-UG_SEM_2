#include <iostream>
#include <stack>
#include <string>

bool is_valid(std::string expression){
    std::stack<int> stack {};
    for(char pos : expression){
        if(pos == '(' || pos == '[' || pos == '{'){
            stack.push(pos);
        }
        else if(pos == ')' ){
            if(stack.top() == '('){ stack.pop(); }
            else {
                return false;
            }
        }
        else if( pos == ']'){
            if(stack.top() == '['){ stack.pop(); }
            else {
                return false;
            }
        }
        else if( pos == '}'){
            if(stack.top() == '{'){ stack.pop(); }
            else {
                return false;
            }        
        }
    }
    return stack.empty(); 
}


int main() {

    std::string testCases[] = {
        "()",
        "([])",
        "{[()]}",
        "((a+b) * [c-d])",
        "{a+[b*(c+d)]}",
        "[({})]",

        "(",
        "([)]",
        "{[(])}",
        "((a+b)",
        "[a+b}}",
        "{[()]"
    };

    int n = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < n; i++) {

        std::cout << "Expression: " << testCases[i] << '\n';

        if (is_valid(testCases[i])) {
            std::cout << "Balanced\n";
        }
        else {
            std::cout << "Not Balanced\n";
        }

        std::cout << "------------------\n";
    }

    return 0;
}