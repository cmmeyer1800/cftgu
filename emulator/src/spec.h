#pragma once

// REGISTER SPECIFICATIONS
#define NUM_REGS 16 // Note: Must be a power of 2
#define REG_WIDTH 32 // Note: Must be 8, 16, 32, or 64

#if REG_WIDTH == 8
    typedef unsigned char reg_t;
#elif REG_WIDTH == 16
    typedef unsigned short reg_t;
#elif REG_WIDTH == 32
    typedef unsigned int reg_t;
#elif REG_WIDTH == 64
    typedef unsigned long reg_t;
#endif