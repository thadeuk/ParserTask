/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpetrer.
 */

#include "interpreter.h"
#include "parser.h"
#include "node.h"

using namespace std;

double Interpreter::execute(string expression)
{
    Parser parser(expression);
    unique_ptr<ASTNode> node = parser.parse();
    if (!parser.error()) 
    {
        if (this->verbose)
            node->prettyPrint();
        double result = node->evaluate();
        return result;
    }
    else {
        cout << "Could not parse expression" << endl;
        return 0;
    }
}
