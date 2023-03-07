#include <vector>
#include <string>

std::string opUndDelimTokens(std::string s) {
    // OPERATORS ----------------------------------------- //
    if (s.compare(">~") == 0) { return "ABTGREATERTHAN_TOKEN"; }
    if (s.compare("<~") == 0) { return "ABTLESSTTHAN_TOKEN"; }
    
    if (s.compare(">") == 0) { return "GREATERTHAN_TOKEN"; }
    if (s.compare("<") == 0) { return "LESSTHAN_TOKEN"; }
    if (s.compare("~") == 0) { return "TILDE_TOKEN"; }
    
    if (s.compare("=") == 0) { return "EQUALTO_TOKEN"; }
    if (s.compare("%") == 0) { return "MODULO_TOKEN"; }
    if (s.compare("/") == 0) { return "FORWARDSLASH_TOKEN"; }
    if (s.compare("*") == 0) { return "MULTIPLY_TOKEN"; }
    if (s.compare("+") == 0) { return "ADDITION_TOKEN"; }
    if (s.compare("-") == 0) { return "SUBTRACT_TOKEN"; }
    // --------------------------------------------------- //
    // DELIMITERS ---------------------------------------- //
    if (s.compare("(") == 0) { return "LPAREN_TOKEN"; }
    if (s.compare(")") == 0) { return "RPAREN_TOKEN"; }
    if (s.compare("[") == 0) { return "LBRACKT_TOKEN"; }
    if (s.compare("]") == 0) { return "RBRACKT_TOKEN"; }
    if (s.compare("{") == 0) { return "LCBRACE_TOKEN"; }
    if (s.compare("}") == 0) { return "RCBRACE_TOKEN"; }

    if (s.compare(":") == 0) { return "COLON_TOKEN"; }
    if (s.compare(";") == 0) { return "SEMICOL_TOKEN"; }
    if (s.compare(".") == 0) { return "PERIOD_TOKEN"; }
    if (s.compare(",") == 0) { return "COMMA_TOKEN"; }
    // --------------------------------------------------- //
    return "INVALID_OPDELIM_TOKEN";
}

std::string keywordToken(std::string s) { 
    // VALID KEYWORDS ------------------------------------ //
    if (s.compare("open") == 0) { return "OPEN_TOKEN"; }
    if (s.compare("close") == 0) { return "_TOKEN"; }
    if (s.compare("iter") == 0) { return "_TOKEN"; }
    if (s.compare("void") == 0) { return "_TOKEN"; }
    if (s.compare("data") == 0) { return "_TOKEN"; }
    if (s.compare("exit") == 0) { return "_TOKEN"; }
    if (s.compare("read") == 0) { return "_TOKEN"; }
    if (s.compare("print") == 0) { return "_TOKEN"; }
    if (s.compare("main") == 0) { return "_TOKEN"; }
    if (s.compare("iff") == 0) { return "_TOKEN"; }
    if (s.compare("then") == 0) { return "_TOKEN"; }
    if (s.compare("let") == 0) { return "_TOKEN"; }
    if (s.compare("func") == 0) { return "_TOKEN"; }
    // --------------------------------------------------- //
    return "INVALID_KEYWORD_TOKEN"; 
    
}

std::string identifierToken() { return "IDENTIFIER_TOKEN"; }
std::string digitToken() { return "DIGIT_TOKEN"; }
