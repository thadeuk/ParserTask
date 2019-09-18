/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#include "node.h"
#include <cmath>

using namespace std;

int ASTNode::getHeight() {
    if (leftNode == NULL && rightNode == NULL)
        return 1;
    if (leftNode == NULL)
        return 1 + rightNode->getHeight();
    if (rightNode == NULL)
        return 1 + leftNode->getHeight();

    return 1 + max(leftNode->getHeight(), rightNode->getHeight());
}

void ASTNode::printFloor(int floor, int indent) {
    if (floor == 0) {
        for (int i = 0; i < indent; i++)
            cout << "\t";
        print();
        return;
    }

    if (leftNode != NULL)
        leftNode->printFloor(floor-1, indent);
    else {
        for (int i = 0; i < indent; i++)
            cout << "\t";
    }
        
    if (rightNode != NULL) {
        rightNode->printFloor(floor-1, indent);
    }
    else {
        for (int i = 0; i < indent; i++)
            cout << "\t";
    }
}

void ASTNode::prettyPrint() {
    int height = getHeight();
    for (int i = 0; i < height; i++) {
        printFloor(i, pow(2, height-i));
        cout << endl;
    }
}

/******************************************************************/
InternalNode::InternalNode(unique_ptr<ASTNode> _left, unique_ptr<ASTNode> _right, char _value) {
    this->leftNode = move(_left);
    this->rightNode = move(_right);
    this->value = _value;
}

void InternalNode::print() const { 
    cout << value;
}

int InternalNode::evaluate() {
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
    cout << (int)value;
}

int LeafNode::evaluate() {
    return value; 
}

