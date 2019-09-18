/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#include "node.h"

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

void ASTNode::printFloor(int floor, int height) {
    if (floor == 0) {
        for (int i = 0; i < height; i++)
            cout << "\t";
        print();
    }

    if (leftNode != NULL)
        leftNode->printFloor(floor-1, height);
    if (rightNode != NULL)
        rightNode->printFloor(floor-1, height);
}

void ASTNode::prettyPrint() {
    int height = getHeight();
    for (int i = 0; i < height; i++) {
        printFloor(i, height-i);
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

