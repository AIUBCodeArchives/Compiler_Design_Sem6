#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {

    string pattern;
    //Any expression manually puting.
    cout << "Enter an Expression: ";
    getline(cin, pattern);

    regex re;
    try {
        re = regex(pattern);
    } catch (const regex_error& e) {
        cerr << "Invalid regular expression: " << e.what() << endl;
        return 1;
    }

    string input;
    cout << "Enter a string to test: ";
    getline(cin, input);

    if (regex_match(input, re)) {
        cout << "The input string matches the pattern!" << endl;
    } else {
        cout << "The input string does NOT match the pattern." << endl;
    }

    return 0;
}
