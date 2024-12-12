#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

bool isDelimiter(char ch) {
    return (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

bool isInteger(const std::string &token) {
    if (token.empty()) return false;
    for (char ch : token) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool isRealNumber(const std::string &token) {
    bool hasDecimal = false;
    if (token.empty()) return false;
    for (char ch : token) {
        if (ch == '.') {
            if (hasDecimal) return false; // Only one decimal point allowed
            hasDecimal = true;
        } else if (!isdigit(ch)) {
            return false;
        }
    }
    return hasDecimal;
}

void categorizeToken(const std::string &token) {
    if (token.empty()) return;

    if (isInteger(token)) {
        std::cout << "Integer: " << token << "\n";
    } else if (isRealNumber(token)) {
        std::cout << "Real number: " << token << "\n";
    } else if (token.size() == 1 && isDelimiter(token[0])) {
        std::cout << "Delimiter: " << token << "\n";
    } else {
        std::cout << "Invalid token: " << token << "\n";
    }
}

void tokenizeLine(const std::string &line) {
    std::istringstream stream(line);
    std::string token;

    while (stream >> token) {
        // Separate potential tokens containing delimiters
        std::string currentToken;
        for (char ch : token) {
            if (isDelimiter(ch)) {
                if (!currentToken.empty()) {
                    categorizeToken(currentToken);
                    currentToken.clear();
                }
                categorizeToken(std::string(1, ch)); // Categorize the delimiter itself
            } else {
                currentToken += ch;
            }
        }
        if (!currentToken.empty()) {
            categorizeToken(currentToken);
        }
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

