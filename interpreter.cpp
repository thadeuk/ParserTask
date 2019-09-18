/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpreter.
 */

#include "interpreter.h"
#include "parser.h"
#include "node.h"

using namespace std;

int Interpreter::execute(const string& expression)
{
    Parser parser(expression);

    unique_ptr<ASTNode> node = parser.parse();
    if (this->verbose)
        node->prettyPrint();
    double value = node->evaluate();
    return value;
}
