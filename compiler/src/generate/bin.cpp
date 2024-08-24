#include <vector>

#include "bin.h"

void process_opcode(std::vector<unsigned int> &bin, Token token){
    switch(token.value){
        case "add":
            bin.push_back(0x01);
            break;
    }
}

void GenBin::ingest_token(Token token){
    switch(token.type){
        case OPCODE:
            process_opcode(bin, token);
            bin.push_back(0x01);
            break;
    }
}

void GenBin::save(){
    
}
