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
    virtual void print() const = 0;
    virtual double evaluate() = 0;

protected:
    unique_ptr<ASTNode> leftNode;
    unique_ptr<ASTNode> rightNode;
    char value;
};

class InternalNode : public ASTNode
{
public:
    InternalNode(unique_ptr<ASTNode> _left, unique_ptr<ASTNode> _right, char _value);
    virtual void print() const;
    virtual double evaluate();

private:
};

class LeafNode : public ASTNode
{
public:
    LeafNode (char _value);
    virtual void print() const;
    virtual double evaluate();

private:
};

