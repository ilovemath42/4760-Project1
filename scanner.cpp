#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "tokens.h"
#include "token.h"

void error_msg(std::string tk_instance, std::string token_ID, int line_num) {
    if (token_ID.compare("LEXICAL_ERROR") == 0) {
        std::cout << "LEXICAL ERROR: invalid character(s): ";
        std::cout << tk_instance << " at line #" << line_num << std::endl;
        exit(EXIT_FAILURE);
    }
}

token scanner(int state, std::vector<char> tk_chars, int line_num) {
    std::string tk_instance(tk_chars.begin(), tk_chars.end());
    std::string tk_ID;
    // ---------------------------------------------------------------------- //
    if ( state == 1 || state == 2 ) { tk_ID = opUndDelimTokens(tk_instance); error_msg(tk_instance, tk_ID, line_num); } // all OP + delim
    if ( state == 3 ) { tk_ID = identifierToken(); error_msg(tk_instance, tk_ID, line_num); } // identifiers
    if ( state == 4 ) { 
        // since identifiers only begin with an underscore, no need to test if word is identifier
        // if it's not a keyword, then it begins with alpha; therefore, lexical error.
        tk_ID = keywordToken(tk_instance); error_msg(tk_instance, tk_ID, line_num);
        
    } // keywords
    if ( state == 5 ) { tk_ID = digitToken(); error_msg(tk_instance, tk_ID, line_num); } // digits
    if ( state == 6 ) { tk_ID = EOFToken(); } // EOF
    // ---------------------------------------------------------------------- //
    token tk;
    tk.tk_ID = tk_ID; tk.tk_instance = tk_instance;  tk.line_num = line_num;
    return tk;
}