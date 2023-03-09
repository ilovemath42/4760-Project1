#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "scanner.h"
#include "FSAT.h"

#include "token.h"


std::vector<char> creating_longTokens(int first_idx, int last_idx, std::string s) {
    // the string is reconverted to char array instead of using a
    // pointer. In-depth explanation in last_IDindex function.
    std::vector<char> temp_chars;
    // this function is used to create the instances for: 
    // identifiers, keywords, and digits after they're validated.
    
    // CONVERT STRING - > CHAR ARRAY ------ //
    int length = s.length();
    char c_array[length + 1];
    
    strcpy(c_array, s.c_str()); 
    // ----------------------------------- //
    for (int x=first_idx; x < last_idx+1; x++) {
        char c = c_array[x];
        temp_chars.push_back(c);
        
    }
    return temp_chars;
}


int last_DIGITindex(int i, std::string s) {
    int last_index = i;
    // CONVERT STRING - > CHAR ARRAY ------ //
    int length = s.length();
    char c_array[length + 1];
    
    strcpy(c_array, s.c_str()); 
    // ----------------------------------- //
    
    for (int x=i+1; x < sizeof(c_array)+1; x++) {
        char c = c_array[x];
        
        // state 4 is alphabet
        if ( state_5(c) == 1 ) { last_index++; }
        else { break; }
    }
    
    return last_index;
}



int last_KEYWindex(int i, std::string s) {
    int last_index = i;
    // CONVERT STRING - > CHAR ARRAY ------ //
    int length = s.length();
    char c_array[length + 1];
    
    strcpy(c_array, s.c_str()); 
    // ----------------------------------- //
    
    for (int x=i+1; x < sizeof(c_array)+1; x++) {
        char c = c_array[x];
        
        // state 4 is alphabet
        if ( state_4(c) == 1 ) { last_index++; }
        else { break; }
    }
    
    return last_index;
}



int last_IDindex(int i, std::string s) {
    // originally had this use a pointer to a char array, but
    // it would randomly cut off valid characters depending
    // on place in string. So, necessary to reconvert.
    int last_index = i;
    // CONVERT STRING - > CHAR ARRAY ------ //
    int length = s.length();
    char c_array[length + 1];
    
    strcpy(c_array, s.c_str()); 
    // ----------------------------------- //
    // +1 to skip opening _
    for (int x=i+1; x < sizeof(c_array)+1; x++) {
        char c = c_array[x];
        
        // state 4 is alphabet
        if ( state_4(c) == 1 ) { last_index++; }
        // state 5 is digits
        else if ( state_5(c) == 1 ) { last_index++; }
        else { break; }
    }
    
    return last_index;
}


void testscanner(int state, std::vector<char> token_chars, int line_num){
    // token is a struct that is declared in token.h and returned from
    // the scanner in the scanner.cpp file. tk is one token's info
    token tk;
    tk = scanner(state, token_chars, line_num);
    std::cout << tk.tk_ID << " " << tk.tk_instance << " line #" << tk.line_num << std::endl;
}


void FA_driver (std::vector<std::string> input_text) {
    int line_num = 1; // line numbering starts at 1 for every file
    
    std::vector<char> token_chars;
    for (int x = 0; x < input_text.size(); x++) {
        std::string s = input_text[x];
        
        // CONVERT STRING - > CHAR ARRAY ------ //
        int length = s.length();
        char c_array[length + 1];
        
        strcpy(c_array, s.c_str()); 
        // ----------------------------------- //
        
        for (int x = 0; x < sizeof(c_array)-1; x++) {
            // STATE 0: INITIAL STATE -------------- //
            char c = c_array[x]; 
            int state = FSA_table(c);
            
            if (isspace(c) || c=='\n') { continue;}
            
            char lookahead = c_array[x+1];
            // ------------------------------------- //
            int last_index; // used for IDs, keywords, and digits
            
            switch(state) {
                case -1:
                // any chracters that aren't valid will produce this error
                std::cout << "LEXICAL ERROR: invalid character" << c;
                std::cout << "at line #" << line_num << "char #" << x;
                exit(EXIT_FAILURE);
                break;
                case 1:
                    // single operator state: no other action needed
                    // send to scanner then clear temp storage.
                    token_chars.push_back(c);
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                break;
                case 2:
                    // since both dual ops' first char have a chance to
                    // be single op, we deal with dual op in if stmt.
                    token_chars.push_back(c);
                    if (lookahead == '~') {
                        token_chars.push_back(lookahead);
                        testscanner(state, token_chars, line_num);
                        token_chars.clear();
                        x++; break; //could also use continue
                    }
                    // this code catches any stray > < that aren't dual OPs
                    // all OP und Delim tokens unsere eine function, so 
                    // state can be 1 and scanner will get token name.
                    
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                break;
                case 3:
                    // finds last valid identifier char then calls function
                    // that turns char vector into complete identifier.
                    last_index = last_IDindex(x, s);
                    token_chars = creating_longTokens(x, last_index, s);
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                    x = last_index;
                break;
                case 4:
                    // scanner sees
                    last_index = last_KEYWindex(x, s);
                    token_chars = creating_longTokens(x, last_index, s);
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                    x = last_index;
                    
                break;
                case 5:
                    // finds/gets valid digit
                    last_index = last_DIGITindex(x, s);
                    token_chars = creating_longTokens(x, last_index, s);
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                    x = last_index;
                break;
                case 6:
                    // processes EOF 
                    token_chars.push_back(c);
                    testscanner(state, token_chars, line_num);
                    token_chars.clear();
                break;
                
            } // end of switch statment
            
            
        }
        line_num++;
    }
}