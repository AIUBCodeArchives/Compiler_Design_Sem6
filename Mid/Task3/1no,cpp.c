
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string keywords[] = {
    "int", "float", "double", "if", "else", "while", "for", "return", "void", "char", "bool", "true", "false", "class", "public", "private", "protected"
};

const char operators[] = { '+', '-', '*', '/', '=', '<', '>', '&', '|', '!', '%', '^' };

bool isKeyword(const std::string &token) {
    for (const std::string &keyword : keywords) {
        if (token == keyword) {
            return true;
        }
    }
    return false;
}

bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isIdentifier(const std::string &token) {
    if (token.empty() || !isAlpha(token[0])) return false;
    for (char ch : token) {
        if (!isAlpha(ch) && !isDigit(ch)) return false;
    }
    return true;
}

bool isOperator(char ch) {
    for (char op : operators) {
        if (ch == op) return true;
    }
    return false;
}

void categorizeToken(const std::string &token) {
    if (isKeyword(token)) {
        std::cout << "Keyword: " << token << "\n";
    } else if (isIdentifier(token)) {
        std::cout << "Identifier: " << token << "\n";
    } else if (token.size() == 1 && isOperator(token[0])) {
        std::cout << "Operator: " << token << "\n";
    } else {
        std::cout << "Invalid token: " << token << "\n";
    }
}

void tokenizeLine(const std::string &line) {
    std::istringstream stream(line);
    std::string token;
    while (stream >> token) {
        categorizeToken(token);
    }
}

int main() {
    std::ifstream file("no1textfile.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        tokenizeLine(line);
    }

    file.close();
    return 0;
}

