/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Test.
 */
#include <iostream>
#include "interpreter.h"

#define ASSERT_EQUAL(x,y) { if (x != y) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl << "Expected " << x << ". Actual " << y << "." << std::endl; return; }

void ShouldUseOperators()
{
    Interpreter interpreter;
    double result = interpreter.execute("1+2+3+4");
    ASSERT_EQUAL(10, result);
    result = interpreter.execute("4/2");
    ASSERT_EQUAL(4, result);
    result = interpreter.execute("4*2");
    ASSERT_EQUAL(8, result);
    result = interpreter.execute("4-2");
    ASSERT_EQUAL(2, result);
    result = interpreter.execute("4+2*3/6");
    ASSERT_EQUAL(5, result);
}

void ShouldGiveParenthesisPreference()
{
    Interpreter interpreter;
    double result = interpreter.execute("1+(2*3)+4");
    ASSERT_EQUAL(11, result);
    result = interpreter.execute("(1+2)*3+4");
    ASSERT_EQUAL(13, result);
    result = interpreter.execute("1+2*(3+4)");
    ASSERT_EQUAL(15, result);
    result = interpreter.execute("1+(2*3+4)");
    ASSERT_EQUAL(11, result);
    result = interpreter.execute("1+(2*(3+4))");
    ASSERT_EQUAL(15, result);
}

void ShouldGiveMultiplicationAndDivisionPreference()
{
    Interpreter interpreter;
    double result = interpreter.execute("1+2*3+4");
    ASSERT_EQUAL(11, result);
    result = interpreter.execute("(1+2+4/4");
    ASSERT_EQUAL(4, result);
    result = interpreter.execute("1+2*3/6)");
    ASSERT_EQUAL(4, result);
    result = interpreter.execute("1-2*3*4)");
    ASSERT_EQUAL(-23, result);
}

void InputExample1()
{
    Interpreter interpreter;
    double result = interpreter.execute("(4 + 5 * (7 - 3)) - 2");
    ASSERT_EQUAL(23, result);
}

void InputExample2()
{
    Interpreter interpreter;
    double result = interpreter.execute("4+5+7/2");
    ASSERT_EQUAL(13, result);
}

int
main()
{
    ShouldUseOperators();
    ShouldGiveParenthesisPreference();
    ShouldGiveMultiplicationAndDivisionPreference();
    InputExample1();
    InputExample2();
    //InputExample3();
    //InputExample4();
}
