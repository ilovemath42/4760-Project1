#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include<vector>

#include "testScanner.h"


std::vector<std::string> comment_destroyer(std::vector<std::string> file_txt) {
    std::vector<std::string> commentless_txt;
    
    for (int x = 0; x < file_txt.size(); x++) {
        std::vector<char> line_chars;
        
        std::string s = file_txt[x];
        // CONVERT STRING - > CHAR ARRAY ------ //
        int length = s.length();
        char c_array[length + 1];
        
        strcpy(c_array, s.c_str()); 
        // ----------------------------------- //
        for( int x = 0; x < sizeof(c_array)-1; x++) {
            char c = c_array[x];
            if ( c == '@') {
                do {x++; c = c_array[x];} while(c!='@');
                continue;
                
            }
            line_chars.push_back(c);
        }
        std::string new_txt(line_chars.begin(), line_chars.end());
        commentless_txt.push_back(new_txt);
        
    }
    // adding in EOF token at end of input
    commentless_txt.push_back("'\0'");
    
    return commentless_txt;
}

std::vector<std::string> getting_input(std::string file_name) {
    std::ifstream file;
    file.open(file_name.c_str());
    
    std::vector<std::string> file_txt; 
    std::string file_line;
    // -------------------------------------------------------------- //
    if ( !file.is_open() ) {
        std::string ERROR_MSG = "ERROR: Could not open the file: ";
        std::cout << ERROR_MSG << "'" << file_name << "'" << std::endl;
        exit ( EXIT_FAILURE ); 
    }
    // -------------------------------------------------------------- //
    while ( getline(file, file_line) ) { file_txt.push_back(file_line); }
    
    std::vector<std::string> commentless_txt = comment_destroyer(file_txt);
    
    
    return commentless_txt;
}


std::vector<std::string> case1_und_case2(){
    std::vector<std::string> input_text;
    std::string input;
    
    while( getline(std::cin, input)) { input_text.push_back(input); }
    
    std::vector<std::string> commentless_txt = comment_destroyer(input_text);
    
    
    return commentless_txt;

    
    
}

int main(int argc, char** argv) {
    std::vector<std::string> input;
    
    if( argc == 1 ) { input = case1_und_case2(); }
    else if( argc == 2 ) { 
        std::string file = argv[1];
        std::string extension = ".sp23";
        std::string file_name = file + extension;
        input = getting_input(file_name); 
    }
    else { std::cout << "Too many arguments! Please try again.\n"; exit(EXIT_FAILURE); }
    
    
    FA_driver(input);
    
    
    // added for readability in PuTTy
    //std::cout << endl; 
    
    return 0;
}
