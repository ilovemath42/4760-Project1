#ifndef SCANNER_H
#define SCANNER_H

#include <vector>

#include "token.h"

token scanner(int state, std::vector<char> tk_chars, int line_num);

#endif