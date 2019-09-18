/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpreter.
 */
#pragma once

#include <iostream>

class InterpreterResult;

class Interpreter
{
public:
    Interpreter(): verbose(false) {};
    // Constructor to print AST option.
    Interpreter(bool _verbose): verbose(_verbose) {};
    // Call parsing functions and handle error.
    InterpreterResult execute(std::string expression);

private:
    // True to print AST tree.
    bool verbose;
};

class InterpreterResult
{
public:
    InterpreterResult() {}
    InterpreterResult(int _value, bool _error): m_value(_value), m_error(_error) {}

    int value() { return m_value; }
    bool error() { return m_error; }

private:
    // Expression result.
    int m_value;
    // Interpreter returned with error.
    bool m_error;

};
