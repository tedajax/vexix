#include "AjaxUtil.h"

namespace ajx
{
   vector<string> &split(const string &str, char delim, vector<string> &tokens)
   {
      stringstream ss(str);
      string token;
      while (std::getline(ss, token, delim)) {
         tokens.push_back(token);
      }
      return tokens;
   }

   vector<string> split(const string &str, char delim)
   {
      vector<string> tokens;
      split(str, delim, tokens);
      return tokens;
   }
}