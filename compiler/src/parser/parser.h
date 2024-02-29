#pragma once

#include <vector>
#include <string>

#include "../token/token.h"

class Parser {
public:
    Parser(std::string data);
    std::vector<Token> parse();

private:
    std::string data;
};