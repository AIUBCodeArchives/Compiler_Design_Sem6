#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

char operators[] = {'+', '-', '*', '/'};

bool isOperators(const string& line) {
    for (int i = 0; i < line.length(); i++) {
        for (int j = 0; j < sizeof(operators) / sizeof(operators[0]); j++) {
            if (line[i] == operators[j]) {
                cout << "Operator: " << line[i] << endl;
                return true;
            }
        }
    }
    return false;
}

char preprocessors[] = {'<', '>', '='};

bool isPreprocessors(const string& line) {
    for (int i = 0; i < line.length(); i++) {
        for (int j = 0; j < sizeof(preprocessors) / sizeof(preprocessors[0]); j++) {
            if (line[i] == preprocessors[j]) {
                cout << "Preprocessor: " << line[i] << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ifstream file("ID.cpp");
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    int op = 0;
    int pre = 0;

    while (getline(file, line)) {
        if (isOperators(line)) {
            op++;
        }
        if (isPreprocessors(line)) {
            pre++;
        }
    }

    cout << "Number of operators: " << op << endl;
    cout << "Number of preprocessors: " << pre << endl;

    return 0;
}
