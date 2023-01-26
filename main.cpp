#include <iostream>
#include <stdio.h>

#include <vector>
#include <string>


using namespace std;


int main(int argc, char **argv) {
    // If only ./a.out given, tell them they made an oopsies and to try again. Else, process what they
    // gave you. The flags are checked in the following else statement.
    if (argc == 1) {
        cout << "Error: no flags used when calling program; there is nothing to process." << endl;
        cout << " - To run program, type ./oss -n # -s # -t # (where # is a positive int)." << endl;
        cout << " - To access the help option, type ./oss -h" << endl;
        cout << "For additional help, please see README.txt, goodbye!" << endl;
    }
    else {
        // checking if the first flag is -h; if it is, then we can just run help command then exit.
        
        string input = argv[1];
        
    }

    return 0;
}

