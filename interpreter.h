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
    // Call parsing functions and handle error
    double execute(std::string expression);
};
