#include <vector>
#include <iostream>

#include "parser.h"



Parser::Parser(std::string data) {
    this->data = data;
}

std::vector<Token> Parser::parse() {
    std::vector<Token> tokens;
    std::string line;

    bool comment = false;
    bool inline_comment = false;

    for (int i = 0; i < this->data.length(); i++) {
    
        // Check for comments
        if (i >= 2) {
            if(this->data[i-1] == '/' && this->data[i] == '/') {
                inline_comment = true;
                continue;
            } else if(this->data[i-1] == '/' && this->data[i] == '*'){
                comment = true;
                continue;
            }
        }

        // End of comment
        if(comment || inline_comment) {
            if (this->data[i] == '\n' && inline_comment) {
                line = "";
                inline_comment = false;
            } else if(comment && this->data[i-1] == '*' && this->data[i] == '/') {
                line = "";
                comment = false;
            }
            continue;
        }

        if (this->data[i] == '\n' || this->data[i] == ' ' || this->data[i] == ';' || this->data[i] == ',') {
            if(line.empty()) continue;

            tokens.push_back(Token(line));
            line = "";
        } else if(i == this->data.length() - 1) {
            if(line.empty()) continue;

            line += this->data[i];
            tokens.push_back(Token(line));
            break;
        } else {
            line += this->data[i];
        }
    }

    return tokens;
}