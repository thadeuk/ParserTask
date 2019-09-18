#include <iostream>
#include <unistd.h>
#include "interpreter.h"

using namespace std;

int
main(int argc, char **argv)
{
    // verbose prints AST tree when true
    bool verbose = false;
    int opt = getopt(argc, argv, "v");
    if (opt != -1)
        verbose = true;

    Interpreter interpreter(verbose);

    string expression;
    while (getline(cin, expression))
    {
        InterpreterResult result = interpreter.execute(expression);
        if (!result.error())
            cout << result.value() << endl;
        else
            cout << "Could not parse expression" << endl;
    }
}
