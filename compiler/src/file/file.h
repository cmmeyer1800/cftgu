#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class File {
    public:
        File(std::string filename);

        std::vector<std::string> read_lines();
        std::string read();

    private:
        std::string filename;
};