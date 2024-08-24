#pragma once

#include "../token/token.h"


class GenBin {
public:
    void ingest_token(Token token);
    void save();

private:
    std::vector<unsigned int> bin;
    unsigned int current;
};