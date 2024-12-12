#include <iostream>
#include <regex>
#include <string>

int main() {
    // Regular expression pattern
    std::string pattern;
    std::cout << "Enter a regex pattern: ";
    std::getline(std::cin, pattern);

    // Compile the regex
    std::regex re;
    try {
        re = std::regex(pattern);
    } catch (const std::regex_error& e) {
        std::cerr << "Invalid regular expression: " << e.what() << std::endl;
        return 1;
    }

    // Input string to test
    std::string input;
    std::cout << "Enter a string to test: ";
    std::getline(std::cin, input);

    // Check for a match
    if (std::regex_match(input, re)) {
        std::cout << "The input string matches the pattern!" << std::endl;
    } else {
        std::cout << "The input string does NOT match the pattern." << std::endl;
    }

    return 0;
}
