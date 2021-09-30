/*
6.Switcheroo

Instructions
Given a string made up of letters a, b, and/or c, switch the position of letters a and b (change a to b and vice versa). 
Leave any incidence of c untouched.

Example:

'acb' --> 'bca'
'aabacbaa' --> 'bbabcabb'
*/

#include <string>

std::string switcheroo(const std::string &s) 
{
  std::string str=s;
  for(int i=0;i<str.size();i++)
  {
    if(str[i]=='a')
        str[i]='b';
    else if(str[i]=='b')
        str[i]='a';
  }
  return str;
}