/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Test.
 */
#include <iostream>
#include "interpreter.h"

#define ASSERT_EQUAL(x,y) { if (x != y) {std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected " << x << ". Actual " << y << "." << std::endl; return false;} }
#define ASSERT_TRUE(x) { if (!x) { std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected value to be true." << std::endl; return false;} }
#define ASSERT_FALSE(x) { if (x) {std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected value to be false." << std::endl; return false;} }
#define ASSERT_ERROR() std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; return false; 

bool ShouldUseOperators()
{
    Interpreter interpreter;
    int result;
    try {
        result = interpreter.execute("0");
        ASSERT_EQUAL(0, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("  1+2+3+    4");
        ASSERT_EQUAL(10, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("4/2                   ");
        ASSERT_EQUAL(2, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute(" 4*2");
        ASSERT_EQUAL(8, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("4-2");
        ASSERT_EQUAL(2, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("4+2*3/6");
        ASSERT_EQUAL(5, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    return true;
}

bool ShouldGiveParenthesisPreference()
{
    Interpreter interpreter;
    int result;

    try {
        result = interpreter.execute("(1)");
        ASSERT_EQUAL(1, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("1+(2*3)+4");
        ASSERT_EQUAL(11, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("(1+2)*3+4");
        ASSERT_EQUAL(13, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }
    
    try {
        result = interpreter.execute("1+2*(3+4)");
        ASSERT_EQUAL(15, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("1+(2*3+4)");
        ASSERT_EQUAL(11, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try { 
        result = interpreter.execute("1+(2*(3+4))");
        ASSERT_EQUAL(15, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    return true;
}

bool ShouldGiveMultiplicationAndDivisionPreference()
{
    Interpreter interpreter;
    int result;

    try {
        result = interpreter.execute("1+2*3+4");
        ASSERT_EQUAL(11, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("1+2+4/4");
        ASSERT_EQUAL(4, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("1+2*3/6");
        ASSERT_EQUAL(2, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    try {
        result = interpreter.execute("1-2*3*4");
        ASSERT_EQUAL(-23, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    return true;
}

bool InputExample1()
{
    Interpreter interpreter;
    try {
        int result = interpreter.execute("(4 + 5 * (7 - 3)) - 2");
        ASSERT_EQUAL(22, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    return true;
}

bool InputExample2()
{
    Interpreter interpreter;
    try {
        int result = interpreter.execute("4+5+7/2");
        ASSERT_EQUAL(12, result);
    } catch(const std::exception& e)
    {
        ASSERT_ERROR();
    }

    return true;
}

bool InputExample3()
{
    Interpreter interpreter;
    try {
        interpreter.execute("10 + 1");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    return true;
}

bool InputExample4()
{
    Interpreter interpreter;
    try {
        interpreter.execute("-10");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    return true;
}

bool ShouldThrowOnInvalidInput()
{
    Interpreter interpreter;
    try {
        interpreter.execute(" ");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("()");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("-1+2");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("1+-2");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("f");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("1+a");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("+");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    try {
        interpreter.execute("asdi asd  as");
        ASSERT_ERROR();
    } catch(const std::exception& e)
    { }

    return true;
}

int
main()
{
    int errorCounter = 0;
    if (!ShouldUseOperators()) errorCounter++;
    if (!ShouldGiveParenthesisPreference()) errorCounter++;
    if (!ShouldGiveMultiplicationAndDivisionPreference()) errorCounter++;
    if (!InputExample1()) errorCounter++;
    if (!InputExample2()) errorCounter++;
    if (!InputExample3()) errorCounter++;
    if (!InputExample4()) errorCounter++;
    if (!ShouldThrowOnInvalidInput()) errorCounter++;

    std::cout << errorCounter << " failures" << std::endl;
}
