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

    if (this->currentToken == '/' || this->currentToken == '*')
        return TokenType::multDivOperator;

    return TokenType::undefined;
}

void Parser::assertTokenType(TokenType tokenType)
{
    if (this->getCurrentTokenType() != tokenType)
    {
        cout << "Could not parse expression"; 
        error = true;
    }
}

void Parser::nextToken()
{
    cin.get(this->currentToken);

    // Ignore spaces and tabs.
    while (this->currentToken == ' '
            || this->currentToken == '\t')
        cin.get(this->currentToken);
}

unique_ptr<ASTNode> Parser::parse()
{
    nextToken();
    return expr();
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
        node = unique_ptr<InternalNode>(new InternalNode(move(node), term(), value));
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

    nextToken();
    assertTokenType(TokenType::leftParen);

    unique_ptr<ASTNode> node = expr();

    nextToken();
    assertTokenType(TokenType::rightParen);

    return node;
}



