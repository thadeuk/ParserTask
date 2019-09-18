/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpetrer.
 */
#pragma once

#include <iostream>

class Interpreter
{
public:
    Interpreter(): verbose(false) {};
    // Constructor to print AST option.
    Interpreter(bool _verbose): verbose(_verbose) {};
    // Call parsing functions and handle error.
    double execute(std::string expression);

private:
    // True to print AST tree.
    bool verbose;
};
