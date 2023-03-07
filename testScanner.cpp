#include <iostream>
#include <vector>
#include <string>

#include "tokens.h"

void testScanner(int state, std::vector<char> tk_chars, int line_num) {
    std::string tk_instance(tk_chars.begin(), tk_chars.end());
    std::string tk_name;
    // ---------------------------------------------------------------------- //
    if ( state == 1 ) { tk_name = opUndDelimTokens(tk_instance); } // all OP + delim
    if ( state == 3 ) { tk_name = identifierToken(); } // identifiers
    if ( state == 4 ) { tk_name = keywordToken(tk_instance); } // keywords
    if ( state == 5 ) { tk_name = digitToken(); } // digits
    // ---------------------------------------------------------------------- //
    
    
    std::cout << tk_name << " " << tk_instance << " " << line_num << std::endl;
}