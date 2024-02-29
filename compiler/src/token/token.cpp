#include "token.h"
#include "../spec.h"

const char * opcodes[] = OPCODES;

Token::Token(std::string data) {
    this->value = data;

    if (!data.empty() && std::all_of(data.begin(), data.end(), ::isdigit)) {
        this->type = NUMBER;
    } else if(data.length() >= 2 && (data[0] == 'R' || data[0] == 'r') &&
              std::all_of(data.begin() + 1, data.end(), ::isdigit)) {
        this->type = REGISTER;
    } else {
        // Either a label or an opcode
        for(int i = 0; i < NUM_OPCODES; i++) {
            if(data == opcodes[i]) {
                this->type = OPCODE;
                return;
            }
        }

        // Not and opcode, so it must be a label
        this->type = LABEL;
    }
}