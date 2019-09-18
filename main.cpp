#include <iostream>
#include "interpreter.h"

using namespace std;

int
main()
{
    Interpreter interpreter;
    string expression;
    while (getline(cin, expression))
    {
        cout << interpreter.execute(expression) << endl;
    }
}
