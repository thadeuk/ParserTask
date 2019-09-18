/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#pragma once

#include <iostream>
#include <memory>

using namespace std;

class ASTNode
{
public:
    ASTNode() {};
    virtual ~ASTNode() {};

    // Print AST tree
    void prettyPrint();
    virtual int evaluate() = 0;
    
protected:
    unique_ptr<ASTNode> leftNode;
    unique_ptr<ASTNode> rightNode;

    // Print node value
    virtual void print() const = 0;

private:
    // These are used for prettyPrint
    int getHeight();
    void printFloor(int floor, int indent);
};

class InternalNode : public ASTNode
{
public:
    InternalNode(unique_ptr<ASTNode> _left, unique_ptr<ASTNode> _right, char _value);
    int evaluate() override;
    char value;

private:
    void print() const override;
};

class LeafNode : public ASTNode
{
public:
    LeafNode (char _value);
    int evaluate() override;
    int value;

private:
    void print() const override;
};

