#pragma once

#include <string>

typedef enum {
    OPCODE,
    REGISTER,
    NUMBER,
    LABEL
} token_t;

class Token {
public:
    Token(std::string data);
    void parse();

    token_t type;
    std::string value;
};