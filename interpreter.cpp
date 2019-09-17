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
    cout << "Parsing..." << endl;
    unique_ptr<ASTNode> node = parser.parse();
    if (!parser.error) 
    {
        cout << "Printing..." << endl;
        node->print();
        cout << "Evaluating..." << endl;
        double result = node->evaluate();
        cout << result << endl;
        return result;
    }
    else {
        cout << "Could not parse expression" << endl;
        return 0;
    }
}
