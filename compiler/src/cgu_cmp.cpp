#include <iostream>
#include <string>
#include <vector>
#include <argparse/argparse.hpp>

#include "file/file.h"
#include "parser/parser.h"
#include "token/token.h"

/*
 * main
 *   DESCRIPTION: This is the main function for the compiler. It contains user
 *                interfaces needed to run the compiler.
 *   INPUTS: Command Line Arguments
 *   RETURN VALUE: Status Code: 0 - Success, else - Failure
 */
int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("CFTGU Assembly Compiler");

    program.add_argument("asm_file")
        .help("Assembly file to compile");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    auto input = program.get("asm_file");
    File file(input);

    std::string lines = file.read();

    Parser *parser = new Parser(lines);
    std::vector<Token> tokens = parser->parse();

    // for(auto token : tokens) {
    //     std::cout << token.value << " | " << token.type << std::endl;
    // }

    return 0;
}
