#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib> // for system(clear) or system(cls)

using namespace std;

bool isKeyword(string word) {
    string keywords[] = {"if", "else", "for", "while", "return", "void",
                         "main", "include", "using", "namespace", "std", "cout", "cin", "endl"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (word == keywords[i]) return true;
    }
    return false;
}

bool isDataType(string word) {
    string dataTypes[] = {"int", "float", "double", "char", "void", "long", "bool"};
    int numDataTypes = sizeof(dataTypes) / sizeof(dataTypes[0]);
    for (int i = 0; i < numDataTypes; i++) {
        if (word == dataTypes[i]) return true;
    }
    return false;
}

void removeDuplicates(string arr[], int& count) {
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < count - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --count; // Reduce count as an element is removed
                --j; // Recheck the current position
            }
        }
    }
}

int main() {
    string input;

    do {
        string keywords[99], dataTypes[99];
        int kIndex = 0, dtIndex = 0;

        //Clear Screen
        system("cls");

        ifstream file("example.cpp");
        if (!file.is_open()) {
            cerr << "File Doesn't Exist" << endl;
            return 1;
        }

        string line, word;
        while (getline(file, line)) {
            for (size_t i = 0; i < line.length(); ++i) {
                if (isspace(line[i]) || ispunct(line[i])) {
                    if (!word.empty()) {
                        if (isKeyword(word)) {
                            keywords[kIndex] = word;
                            kIndex++;
                        } else if (isDataType(word)) {
                            dataTypes[dtIndex] = word;
                            dtIndex++;
                        }
                        word.clear();
                    }
                } else {
                    word += line[i];
                }
            }
            if (!word.empty()) {
                if (isKeyword(word)) {
                    keywords[kIndex] = word;
                    kIndex++;
                } else if (isDataType(word)) {
                    dataTypes[dtIndex] = word;
                    dtIndex++;
                }
                word.clear();
            }
        }

        file.close();

        removeDuplicates(keywords, kIndex);
        removeDuplicates(dataTypes, dtIndex);

        // Display results
        cout << "Keywords -> ";
        for (int i = 0; i < kIndex; ++i) cout << keywords[i] << " ";
        cout << endl;

        cout << "Data Types -> ";
        for (int i = 0; i < dtIndex; ++i) cout << dataTypes[i] << " ";
        cout << endl;

        // Print totals
        cout << "Total Keywords: " << kIndex << endl;
        cout << "Total Data Types: " << dtIndex << endl;

        cout << "Reload Again (yes/no)? ";
        cin >> input;

    } while (input == "yes");

    return 0;
}
