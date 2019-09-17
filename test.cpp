#include <iostream>
#include "interpreter.h"

using namespace std;

template <typename T>
bool AssertEqual(T expected, T result) {
    if (expected == result)
        return true;
    return false;
}

bool ShouldCalculate()
{
    Interpreter interpreter;
    double result = interpreter.execute("1+2+3+4");
    AssertEqual((double)10, result);
}

int
main()
{
    ShouldCalculate();
    
}
