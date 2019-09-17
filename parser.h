/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Parser.
 * expr   : term ((PLUS | MINUS) term)*
 * term   : factor ((MUL | DIV) factor)*
 * factor : INTEGER | LPAREN expr RPAREN
 */
#pragma once
#include <iostream>
#include <memory>
#include "node.h"

enum TokenType
{
    leftParen,
    rightParen,
    plusMinusOperator,
    multDivOperator,
    number,
    undefined
};

class Parser
{
public:
    bool error;

    Parser(string expression);
    std::unique_ptr<ASTNode> parse();
    void nextToken();

private:
    string expression;
    char currentToken;
    int currentTokenIdx;

    TokenType getCurrentTokenType();
    void updateCurrentToken();
    void assertTokenType(TokenType);

    std::unique_ptr<ASTNode> expr();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();
};
