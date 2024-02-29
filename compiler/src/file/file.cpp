#include <iostream>
#include <fstream>
#include <vector>

#include "file.h"

File::File(std::string filename) {
    this->filename = filename;
}

std::vector<std::string> File::read_lines() {
    std::ifstream file(this->filename);
    std::vector<std::string> lines;

    for( std::string line; getline( file, line ); ){
        lines.push_back(line);
    }

    return lines;
}

std::string File::read(){
    std::ifstream file(this->filename);
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    return content;
}