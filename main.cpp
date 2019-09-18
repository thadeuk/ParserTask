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
        try {
            cout << interpreter.execute(expression) << endl;
        } catch (const exception& e) {
            cout << "Could not evaluate expression." << endl;
        }
    }
}
