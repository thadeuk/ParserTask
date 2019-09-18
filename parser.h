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
    // Constructor with expression to be parsed.
    Parser(const string& expression);
    // Init parsing.
    std::unique_ptr<ASTNode> parse();
    // Put next token in the currentToken variable.
    void nextToken();

private:
    // Current string to be parsed.
    const string& expression;
    // Current token to be parsed.
    char currentToken;
    // Current token index related to expression string.
    int currentTokenIdx;

    TokenType getCurrentTokenType();
    // Prints error message and set error flag to true
    void assertTokenType(TokenType);

    std::unique_ptr<ASTNode> expr();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();
};
