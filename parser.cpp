/**
 * @author Thadeu <thadeutucci@gmail.com>
 * @date 2019
 * Parser.
 * expr   : term ((PLUS | MINUS) term)*
 * term   : factor ((MUL | DIV) factor)*
 * factor : INTEGER | LPAREN expr RPAREN
 */
#include "parser.h"

using namespace std;

Parser::Parser(const string& _expression) : expression(_expression)
{
   this->currentTokenIdx = -1;
}

unique_ptr<ASTNode> Parser::parse()
{
    nextToken();
    unique_ptr<ASTNode> node = expr();

    // Error if parser could not read to the end of expression
    if (static_cast<size_t>(currentTokenIdx) < this->expression.size()) {
       throw invalid_argument("Could not parse expression to the end.");
    }
    return node;
}

void Parser::nextToken()
{
    this->currentTokenIdx++;
    if (static_cast<size_t>(currentTokenIdx) < this->expression.size())
        this->currentToken = this->expression.at(this->currentTokenIdx);

    // Ignore spaces and tabs.
    while (this->currentToken == ' '
            || this->currentToken == '\t') {
        this->currentTokenIdx++;
        if (static_cast<size_t>(currentTokenIdx) >= this->expression.size())
            break;

        this->currentToken = this->expression.at(this->currentTokenIdx);
    }
}

TokenType Parser::getCurrentTokenType()
{
    if (this->currentToken == '(')
        return TokenType::leftParen;

    if (this->currentToken == ')')
        return TokenType::rightParen;

    if (this->currentToken >= '0' && this->currentToken <= '9')
        return TokenType::number;

    if (this->currentToken == '+' || this->currentToken == '-')
        return TokenType::plusMinusOperator;

    if (this->currentToken == '*' || this->currentToken == '/')
        return TokenType::multDivOperator;

    return TokenType::undefined;
}

void Parser::assertTokenType(TokenType tokenType)
{
    if (this->getCurrentTokenType() != tokenType)
    {
        throw invalid_argument("unexpected token.");
    }
}

unique_ptr<ASTNode> Parser::expr()
{
    unique_ptr<ASTNode> node = term();

    while (getCurrentTokenType() == TokenType::plusMinusOperator)
    {
        char value = this->currentToken;
        nextToken();
        node = unique_ptr<InternalNode>(new InternalNode(std::move(node), term(), value));
    }
    return node;
}

unique_ptr<ASTNode> Parser::term()
{
    unique_ptr<ASTNode> node = factor();

    while (getCurrentTokenType() == TokenType::multDivOperator)
    {
        char value = this->currentToken;
        nextToken();
        node = unique_ptr<InternalNode>(new InternalNode(move(node), factor(), value));
    }
    return node;
}

unique_ptr<ASTNode> Parser::factor()
{
    if (getCurrentTokenType() == TokenType::number) {
        char value = this->currentToken;
        nextToken();
        return unique_ptr<LeafNode>(new LeafNode(value));
    }

    assertTokenType(TokenType::leftParen);

    nextToken();
    unique_ptr<ASTNode> node = expr();

    assertTokenType(TokenType::rightParen);
    nextToken();

    return node;
}
