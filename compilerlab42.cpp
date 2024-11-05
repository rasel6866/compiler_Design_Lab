#include <iostream>
#include <fstream>
#include <set>
#include <regex>
#include <string>

// Set of C++ keywords
const std::set<std::string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "namespace", "new",
    "operator", "private", "protected", "public", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "template", "this", "throw", "try", "typedef", "union", "unsigned",
    "using", "virtual", "void", "volatile", "while", "include"
};

// Set of C++ operators
const std::set<std::string> operators = {
    "+", "-", "*", "/", "%", "=", ">", "<", "!", "&", "|", "^", "~", "++", "--", "==", "!=", ">=",
    "<=", "&&", "||", "<<", ">>", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="
};

// Function to check if a token is a keyword
bool isKeyword(const std::string& token) {
    return keywords.find(token) != keywords.end();
}

// Function to check if a token is an operator
bool isOperator(const std::string& token) {
    return operators.find(token) != operators.end();
}

int main() {
    std::ifstream file("sample_code.txt");
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::set<std::string> identifiedKeywords, identifiedOperators, identifiedIdentifiers;

    while (getline(file, line)) {
        // Regular expression to match tokens (words or operators)
        std::regex tokenRegex(R"([\w#]+|[+\-*/%=<>!&|^~]+)");
        auto tokensBegin = std::sregex_iterator(line.begin(), line.end(), tokenRegex);
        auto tokensEnd = std::sregex_iterator();

        for (auto it = tokensBegin; it != tokensEnd; ++it) {
            std::string token = it->str();

            if (isKeyword(token)) {
                identifiedKeywords.insert(token);
            } else if (isOperator(token)) {
                identifiedOperators.insert(token);
            } else if (std::regex_match(token, std::regex(R"([a-zA-Z_]\w*)"))) {
                // If it's not a keyword or operator, it might be an identifier
                identifiedIdentifiers.insert(token);
            }
        }
    }

    file.close();

    // Output results
    std::cout << "Keywords:\n";
    for (const auto& keyword : identifiedKeywords) {
        std::cout << keyword << "\n";
    }

    std::cout << "\nOperators:\n";
    for (const auto& op : identifiedOperators) {
        std::cout << op << "\n";
    }

    std::cout << "\nIdentifiers:\n";
    for (const auto& id : identifiedIdentifiers) {
        std::cout << id << "\n";
    }

    return 0;
}

