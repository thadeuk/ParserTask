/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpetrer.
 */

#include "interpreter.h"
#include "parser.h"
#include "node.h"

using namespace std;

InterpreterResult Interpreter::execute(string expression)
{
    Parser parser(expression);
    unique_ptr<ASTNode> node = parser.parse();
    if (!parser.error()) 
    {
        if (this->verbose)
            node->prettyPrint();
        double value = node->evaluate();
        return InterpreterResult(value, false);
    }
    else {
        return InterpreterResult(0, true);
    }
}
