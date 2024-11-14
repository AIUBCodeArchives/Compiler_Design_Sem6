#include <iostream>
#include <cstring> // For strcmp
using namespace std;

bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isValidDataType(const char* word) {
    const char* validTypes[] = {"int", "float", "double", "char", "bool", "void"};
    for (int i = 0; i < 6; ++i) {
        if (strcmp(word, validTypes[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidVariableDeclaration(const char* statement) {
    // Skip leading spaces
    int i = 0;
    while (statement[i] == ' ') {
        i++;
    }

    // Extract type: Read the first word (type)
    char type[20];
    int typeIndex = 0;
    while (statement[i] != ' ' && statement[i] != '\0') {
        type[typeIndex++] = statement[i++];
    }
    while (statement[i] == ' ') {
        i++;
    }

    char variable[20];
    int varIndex = 0;
    while (statement[i] != ' ' && statement[i] != ';' && statement[i] != '\0') {
        variable[varIndex++] = statement[i++];
    }

    // Check if a valid type and variable name
    if (isValidDataType(type) && isAlpha(variable[0])) {
        return true;
    }

    return false;
}

// Function to check if a function declaration is valid
bool isValidFunctionDeclaration(const char* statement) {
    // Skip leading spaces
    int i = 0;
    while (statement[i] == ' ') {
        i++;
    }

    // Extract type: Read the first word (type)
    char type[20];
    int typeIndex = 0;
    while (statement[i] != ' ' && statement[i] != '\0') {
        type[typeIndex++] = statement[i++];
    }

    // Skip spaces between type and function name
    while (statement[i] == ' ') {
        i++;
    }

    // Extract function name: Read the second word (function name)
    char funcName[20];
    int funcIndex = 0;
    while (statement[i] != '(' && statement[i] != '\0') {
        funcName[funcIndex++] = statement[i++];
    }

    // Check if the function name starts with an alphabet and type is valid
    if (isValidDataType(type) && isAlpha(funcName[0])) {
        return true;
    }

    return false;
}

// Function to check if a function definition is valid
bool isValidFunctionDefinition(const char* statement) {
    // Skip leading spaces
    int i = 0;
    while (statement[i] == ' ') {
        i++;
    }

    // Extract type: Read the first word (type)
    char type[20];
    int typeIndex = 0;
    while (statement[i] != ' ' && statement[i] != '\0') {
        type[typeIndex++] = statement[i++];
    }

    // Skip spaces between type and function name
    while (statement[i] == ' ') {
        i++;
    }

    // Extract function name: Read the second word (function name)
    char funcName[20];
    int funcIndex = 0;
    while (statement[i] != '(' && statement[i] != '\0') {
        funcName[funcIndex++] = statement[i++];
    }

    // Skip spaces between function name and opening parenthesis '('
    while (statement[i] == ' ') {
        i++;
    }

    // Check if the function definition ends with "() {"
    if (statement[i] == '(' && statement[i + 1] == ')' && statement[i + 2] == ' ' && statement[i + 3] == '{') {
        // Check if the type is valid and function name is alphabetic
        if (isValidDataType(type) && isAlpha(funcName[0])) {
            return true;
        }
    }

    return false;
}

int main() {
    char code[300]; 

    // Example user input: variable declarations, function declarations, and function definitions
     cout<< "Enter a line of code: ";
     cin.getline(code, 300);

    if (isValidVariableDeclaration(code)) {
        cout<< "This is a valid variable declaration." <<endl;
    }
    else if (isValidFunctionDeclaration(code)) {
        cout<< "This is a valid function declaration." <<endl;
    }
    else if (isValidFunctionDefinition(code)) {
       cout<< "This is a valid function definition." <<endl;
    }
    else {
      cout<< "The statement is not valid." <<endl;
    }

    return 0;
}
