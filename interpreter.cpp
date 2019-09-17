/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Expression interpetrer.
 */

#include "interpreter.h"
#include "parser.h"
#include "node.h"

using namespace std;

void Interpreter::interprete()
{
    Parser parser;
    unique_ptr<ASTNode> node = parser.parse();
    cout << "end of parsing... Printing..." << endl;
    if (!parser.error) 
    {
        node->print();
        cout << "end of printing... Evaluating..." << endl;
        cout << node->evaluate() << endl;
    }
}
