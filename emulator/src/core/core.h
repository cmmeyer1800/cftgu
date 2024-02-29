#pragma once

#include "../spec.h"

class Core {
public:
    Core();

    reg_t get_reg(int reg_num);
    reg_t* get_regs();
    void set_reg(int reg_num, reg_t value);
private:
    reg_t regs[NUM_REGS];
};