#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include<algorithm>

using namespace std;

// Function to check if the sentence starts with a capital letter
bool startsWithCapital(const string& sentence) {
    if (!sentence.empty() && isupper(sentence[0])) {
        return true;
    } else {
        cout << "The sentence should start with a capital letter.\n";
        return false;
    }
}

// Function to check if the sentence has correct punctuation at the end (e.g., period, question mark, exclamation mark)
bool endsWithPunctuation(const string& sentence) {
    if (!sentence.empty() && (sentence.back() == '.' || sentence.back() == '?' || sentence.back() == '!')) {
        return true;
    } else {
        cout << "The sentence should end with a period, question mark, or exclamation mark.\n";
        return false;
    }
}

// Function to check spelling against a list of common programming and mathematics words
bool checkSpelling(const string& sentence) {
    // List of common programming and mathematics words
    vector<string> commonWords = {
        "variable", "function", "class", "object", "loop", "algorithm", "array", 
        "matrix", "integer", "float", "string", "pointer", "recursion", "syntax", 
        "compiler", "debug", "error", "parameter", "argument", "operation", "expression",
        "sum", "difference", "product", "quotient", "equal", "greater", "less", "than", 
        "if", "else", "then", "while", "for", "and", "or", "not", "equals", "modulus", "absolute"
    };

    // Convert sentence to lowercase and split into words
    istringstream stream(sentence);
    string word;
    bool allWordsCorrect = true;

    while (stream >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Manually convert word to lowercase (without using transform)
        for (char &c : word) {
            c = tolower(c);
        }

        // Check if the word is in the list of common words
        bool isCorrect = false;
        for (const auto& commonWord : commonWords) {
            if (word == commonWord) {
                isCorrect = true;
                break;
            }
        }

        if (!isCorrect) {
            cout << "Possible spelling mistake: " << word << "\n";
            allWordsCorrect = false;
        }
    }

    return allWordsCorrect;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    bool isCapitalCorrect = startsWithCapital(sentence);
    bool isPunctuationCorrect = endsWithPunctuation(sentence);
    bool isSpellingCorrect = checkSpelling(sentence);

    if (isCapitalCorrect && isPunctuationCorrect && isSpellingCorrect) {
        cout << "The sentence has correct capitalization, punctuation, and spelling.\n";
    } else {
        cout << "The sentence has grammar issues.\n";
    }

    return 0;
}
