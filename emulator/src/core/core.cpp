#include "core.h"

/*
 * Core::Core
 *   DESCRIPTION: Constructor for Core class
 *   SIDE EFFECTS: initializes all registers to 0
 */
Core::Core() {
    for (int i = 0; i < NUM_REGS; i++) {
        regs[i] = 0;
    }
}

/*
 * Core::get_reg
 *   DESCRIPTION: Returns the value of the register at the given index
 *   INPUTS: reg_num - the index of the register to get
 *   RETURN VALUE: register file value at the given index
 */
reg_t Core::get_reg(int reg_num) {
    return regs[reg_num];
}

/*
 * Core::get_regs
 *   DESCRIPTION: Returns a pointer to the register file
 *   RETURN VALUE: pointer to the register file
 */
reg_t* Core::get_regs() {
    return regs;
}

/*
 * Core::set_reg
 *   DESCRIPTION: Sets the value of the register at the given index
 *   INPUTS: reg_num - the index of the register to set
 *           value   - the value to set the register to
 *   SIDE EFFECTS: sets the value of the register at the given index
 */
void Core::set_reg(int reg_num, reg_t value) {
    regs[reg_num] = value;
}
