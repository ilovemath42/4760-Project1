#ifndef TOKENS_H
#define TOKENS_H

std::string opUndDelimTokens(std::string s);
std::string keywordToken(std::string s);
std::string identifierToken();
std::string digitToken();
std::string EOFToken();

#endif