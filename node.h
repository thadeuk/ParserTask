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
    virtual double evaluate() = 0;
    void prettyPrint();
    
protected:
    virtual void print() const = 0;
    unique_ptr<ASTNode> leftNode;
    unique_ptr<ASTNode> rightNode;
    char value;

private:
    int getHeight();
    void printFloor(int floor, int height);
};

class InternalNode : public ASTNode
{
public:
    InternalNode(unique_ptr<ASTNode> _left, unique_ptr<ASTNode> _right, char _value);
    virtual double evaluate();

private:
    void print() const;
};

class LeafNode : public ASTNode
{
public:
    LeafNode (char _value);
    virtual double evaluate();

private:
    void print() const;
};

