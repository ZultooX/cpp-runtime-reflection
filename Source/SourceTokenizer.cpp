#include "SourceTokenizer.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

void Lexer::Tokenize(const char* filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filepath << '\n';
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string source = buffer.str();

    std::regex pattern(R"(\[\[(.*?)\]\]\s*([a-zA-Z_][a-zA-Z0-9_:<>*]*)\s*([a-z]+))");

    std::sregex_iterator begin(source.begin(), source.end(), pattern);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it)
    {
        const std::smatch& match = *it;
        std::string attributes = match[1].str();
        std::string type = match[2].str();
        std::string name = match[3].str();

        std::cout << attributes << std::endl;
        std::cout << type << std::endl;
        std::cout << name << std::endl;
        std::cout << "==========================================" << std::endl;
    }
}