/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#include "node.h"

using namespace std;

void InternalNode::print() const { 
    cout << value << endl;
    leftNode->print();
    rightNode->print();
}

double InternalNode::evaluate() {
    if (value == '+')
        return leftNode->evaluate() + rightNode->evaluate(); 
    else if (value == '-')
        return leftNode->evaluate() - rightNode->evaluate(); 
    else if (value == '/')
        return leftNode->evaluate() / rightNode->evaluate(); 
    else
        return leftNode->evaluate() * rightNode->evaluate(); 
}

/******************************************************************/

void LeafNode::print() const {
    cout << (int)value << " " ;
}

double LeafNode::evaluate() {
    return value; 
}

