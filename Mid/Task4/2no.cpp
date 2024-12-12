#include <iostream>
#include <stack>

using namespace std;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isValidExpression(const std::string& expression) {
    stack<char> parentheses;
    int length = expression.length();
    bool hasEqualSign = false; 

    // checking each character in the expression
    for (size_t i = 0; i < length; ++i) {
        char current = expression[i];

        //characters
        if (!isDigit(current) && current != '+' && current != '-' &&
            current != '*' && current != '/' && current != '(' &&
            current != ')' && current != '=' && current != ' ') {
            return false; // Invalid character detected
        }

        //parentheses
        if (current == '(') {
            parentheses.push(current);
        }

        if (current == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false; // Mismatched or unbalanced parentheses
            }
            parentheses.pop();
        }

        //operator
        if (current == '+' || current == '-' || current == '*' || current == '/') {
            if (i == 0 || i == length - 1) {
                return false; 
            }
            if (expression[i - 1] == '+' || expression[i - 1] == '-' ||
                expression[i - 1] == '*' || expression[i - 1] == '/' ||
                expression[i - 1] == '(') {
                return false; 
            }
            if (expression[i + 1] == ')' || expression[i + 1] == '+' ||
                expression[i + 1] == '-' || expression[i + 1] == '*' ||
                expression[i + 1] == '/') {
                return false; 
            }
        }

        //equal
        if (current == '=') {
            if (hasEqualSign) {
                return false; // More than one equality sign
            }
            if (i == 0 || i == length - 1) {
                return false; // Equality sign at the start or end
            }
            hasEqualSign = true;
        }
    }

    // Check if there are unmatched opening parentheses left
    return parentheses.empty();
}

int main() {
    std::string expressions[] = {
        "3 + (5 * 2)",       
        "4 * (3 + 2))",      
        "(2 + 3 * (7 - 5)",  
        "4 / + 5",           
        "8 * (3 - 2)",       
        "5 + 3 * ()",        
        "5 = 3 + 2",         
        "6 = 1 + 2",         
        "5 = 3 + 2 = 4",     
        "= 3 + 2",           
        "5 + 3 = ",          
        "5 + 3 * = 2"        
    };

    for (const auto& expr : expressions) {
for (const auto& expr : expressions) {

        if(isValidExpression(expr) == true){
            cout << "Expression: " << expr << " -> Valid."<<endl;
        }
        else{
            cout << "Expression: " << expr << " -> Invalid."<<endl;    
        }
    }

    return 0;
}
