#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using std::string;
using std::stringstream;
using std::vector;

#if _DEBUG
    #define DEBUG_MSG(x) std::cout << x;
    #define DEBUG_MSGLN(x) std::cout << x << std::endl;
    #define LOAD_MSG(x) std::cout << x << "... ";
    #define DONE std::cout << "Done\n";
    #define FAILED std::cout << "Failed\n";
#else
    #define DEBUG_MSG(x)
    #define DEBUG_MSGLN(x)
    #define LOAD_MSG(x)
    #define DONE
    #define FAILED
#endif

namespace ajx
{
    vector<string> &split(const string &str, char delim, vector<string> &tokens);
    vector<string> split(const string &str, char delim);
}