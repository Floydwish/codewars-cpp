//1.Reversed Strings

//Instructions
//Complete the solution so that it reverses the string passed into it.
//'world'  =>  'dlrow'


#include <string>
using namespace std ; 

// my solution
string reverseString (string str )
{
  // your Code is Here ... enjoy !!!
  string tmp;
  for(int i=str.length()-1;i>=0;i--)
    {
    tmp+=str[i];
  }
  return tmp ;
}

// other's solution
#include <algorithm>
#include <string>

std::string reverseString(const std::string& str) {
  return std::string(str.rbegin(), str.rend());
}


//other's solution
#include <algorithm>
#include <string>

std::string reverseString(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}