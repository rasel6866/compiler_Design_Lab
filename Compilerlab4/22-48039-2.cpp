#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool endsWithSemicolon(const std::string& line) {
    auto trimmedLine = line;
    trimmedLine.erase(std::find_if(trimmedLine.rbegin(), trimmedLine.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), trimmedLine.end());

    return !trimmedLine.empty() && trimmedLine.back() == ';';
}

int main() {
    std::ifstream file("E:\\AIUB\\AIUB 8th FALL\\Shannaj Parvin Com.Design\\MID Tearm\\Compiler all code\\CompLab5.cpp.cpp");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (endsWithSemicolon(line)) {
            std::cout << "Line " << lineNumber << " ends with a semicolon." << std::endl;
        } else {
            std::cout << "Line " << lineNumber << " does NOT end with a semicolon." << std::endl;
        }
        ++lineNumber;
    }

    file.close();
    return 0;
}

