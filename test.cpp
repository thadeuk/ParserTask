#include <iostream>
#include "parser.h"

using namespace std;

int
main()
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
