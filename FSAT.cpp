#include <stdio.h>
#include <ctype.h>


bool state_1(char c) {
    // state 1 is for all single operators + delims; all of these don't have a
    // second state, so FINAL. No other processing needed: go next char
    if ( c == '{' || c == '}' || c == '.' || c == '=' || c == '*' ||
         c == '[' || c == ']' || c == ',' || c == '%' || c == '-' || 
         c == '(' || c == ')' || c == '~' || c == '/' || c == '+' ||
         c == ':' || c == ';'  ) { return true; }
    // else it's not a single op return false
    return false;
}

bool state_2(char c) {
    // state 2 operator and dilimiters have 2 possible final states
    if ( c == '>' || c == '<') { return true; } // operators
    return false;
}

bool state_3(char c) {
    // digits + alpha are not included in this state because they cannot be used to 
    // start an identifier; because, isdigit() is used in a later state to signal
    // start of a digit, so if it were included here, it would be a NDFSA.
    if ( c == '_' ) { return true; } // identifiers + keywords
    // the driver determines if an ID is a keyword; state 3 catches both
    return false;
}

bool state_4(char c) {
    if ( isalpha(c) ) { return true; } // maybe keyword
    return false;
}

bool state_5(char c) {
    // isdigit() is reserved to signal digits since 
    if ( isdigit(c) ) { return true; } // digits
    // done checking bc only ints allowed
    return false;
}

bool state_6(char c) {
    if ( c == '\'' ) { return true; } // EOF
    return false;
}

int FSA_table(char c) {
    int state = -1;
    // ---------------------------------------------------------------------- //
    if ( state_1(c) ) { state = 1; } // single OP
    if ( state_2(c) ) { state = 2; } // double OP
    if ( state_3(c) ) { state = 3; } // identifiers 
    if ( state_4(c) ) { state = 4; } // keywords
    if ( state_5(c) ) { state = 5; } // digits
    if ( state_6(c) ) { state = 6; } // EOF 
    // ---------------------------------------------------------------------- //
    // anything that doesn't exsist in a state is returned as an error (-1)
    return state;
}


