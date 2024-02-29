#include <iostream>

#include "core/core.h"
#include "spec.h"

/*
 * main
 *   DESCRIPTION: This is the main function for the emulator. It contains user
 *                interfaces needed to run the emulator.
 *   INPUTS: Command Line Arguments
 *   RETURN VALUE: Status Code: 0 - Success, else - Failure
 */
int main(){
    Core *core = new Core();

    reg_t *regs = core->get_regs();
    for(int i = 0; i < NUM_REGS; i++){
        std::cout << "Register " << i << ": " << regs[i] << std::endl;
    }

    delete core;

    return 0;
}