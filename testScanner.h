#ifndef TESTSCANNER_H
#define TESTSCANNER_H

#include <vector>
#include <string>

void FA_driver(std::vector<std::string> input_text);
void creating_longTokens(int first_idx, int last_idx, std::string s);
int last_IDindex(int i, std::string s);
int last_KEYWindex(int i, std::string s);
int last_DIGITindex(int i, std::string s);

#endif