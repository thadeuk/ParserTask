/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Test.
 */
#include <iostream>
#include "interpreter.h"

#define ASSERT_EQUAL(x,y) { if (x != y) {std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected " << x << ". Actual " << y << "." << std::endl; return;} }
#define ASSERT_TRUE(x) { if (!x) { std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected value to be true." << std::endl; return;} }
#define ASSERT_FALSE(x) { if (x) {std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected value to be false." << std::endl; return;} }

void ShouldUseOperators()
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
}

void ShouldGiveParenthesisPreference()
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
}

void ShouldGiveMultiplicationAndDivisionPreference()
{
    Interpreter interpreter;
    InterpreterResult result;

    result = interpreter.execute("1+2*3+4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(11, result.value());

    result = interpreter.execute("1+2+4/4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(3, result.value());

    result = interpreter.execute("1+2*3/6");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(4, result.value());

    result = interpreter.execute("1-2*3*4");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(-23, result.value());
}

void InputExample1()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("(4 + 5 * (7 - 3)) - 2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(22, result.value());
}

void InputExample2()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("4+5+7/2");
    ASSERT_FALSE(result.error());
    ASSERT_EQUAL(12, result.value());
}

void InputExample3()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("10 + 1");
    ASSERT_TRUE(result.error());
}

void InputExample4()
{
    Interpreter interpreter;
    InterpreterResult result = interpreter.execute("-10");
    ASSERT_TRUE(result.error());
}

int
main()
{
    ShouldUseOperators();
    ShouldGiveParenthesisPreference();
    ShouldGiveMultiplicationAndDivisionPreference();
    InputExample1();
    InputExample2();
    InputExample3();
    InputExample4();
}
