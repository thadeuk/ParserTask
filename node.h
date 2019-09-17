/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * AST nodes.
 */
#pragma once
#include <iostream>
#include <memory>

class ASTNode
{
public:
    ASTNode() {};
    virtual ~ASTNode() {};
    virtual void print() const = 0;
    virtual double evaluate() = 0;
};

class InternalNode : public ASTNode
{
private:
    std::unique_ptr<ASTNode> leftNode;
    std::unique_ptr<ASTNode> rightNode;
    char value;
public:
    InternalNode(std::unique_ptr<ASTNode> _left, std::unique_ptr<ASTNode> _right, char _value): leftNode(std::move(_left)), rightNode(std::move(_right)), value(_value) {};
    virtual void print() const;
    virtual double evaluate();
};

class LeafNode : public ASTNode
{
private:
    uint8_t value;
public:
    LeafNode (uint8_t _value) : value(_value) {};
    LeafNode (char _value) : value(_value-'0') {};
    virtual void print() const;
    virtual double evaluate();
};

