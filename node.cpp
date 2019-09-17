/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#include "node.h"

using namespace std;

InternalNode::InternalNode(unique_ptr<ASTNode> _left, unique_ptr<ASTNode> _right, char _value) {
    this->leftNode = move(_left);
    this->rightNode = move(_right);
    this->value = _value;
}

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

LeafNode::LeafNode(char _value) {
    this->value = _value - '0';
}

void LeafNode::print() const {
    cout << (int)value << endl ;
}

double LeafNode::evaluate() {
    return value; 
}

