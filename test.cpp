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

bool ShouldUseOperators()
{
    Interpreter interpreter;
    InterpreterResult result;
    result = interpreter.execute("1+2+3+4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(10, result.value());

    result = interpreter.execute("4/2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(2, result.value());

    result = interpreter.execute("4*2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(8, result.value());

    result = interpreter.execute("4-2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(2, result.value());

    result = interpreter.execute("4+2*3/6");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(5, result.value());

    return true;
}

bool ShouldGiveParenthesisPreference()
{
    Interpreter interpreter;
    InterpreterResult result;
    result = interpreter.execute("1+(2*3)+4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(11, result.value());

    result = interpreter.execute("(1+2)*3+4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(13, result.value());
    
    result = interpreter.execute("1+2*(3+4)");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(15, result.value());
    
    result = interpreter.execute("1+(2*3+4)");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(11, result.value());
    
    result = interpreter.execute("1+(2*(3+4))");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(15, result.value());

    return true;
}

bool ShouldGiveMultiplicationAndDivisionPreference()
{
    Interpreter interpreter;
    InterpreterResult result;

    result = interpreter.execute("1+2*3+4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(11, result.value());

    result = interpreter.execute("1+2+4/4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(4, result.value());

    result = interpreter.execute("1+2*3/6");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(2, result.value());

    result = interpreter.execute("1-2*3*4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(-23, result.value());

    return true;
}

bool InputExample1()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("(4 + 5 * (7 - 3)) - 2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(22, result.value());

    return true;
}

bool InputExample2()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("4+5+7/2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(12, result.value());

    return true;
}

bool InputExample3()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("10 + 1");
    ASSERT_TRUE(result.error());

    return true;
}

bool InputExample4()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("-10");
    ASSERT_TRUE(result.error());
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

    std::cout << errorCounter << " failures" << std::endl;
}
