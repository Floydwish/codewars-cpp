/*
8.Alternate capitalization

Instructions
Given a string, capitalize the letters that occupy even indexes and odd indexes separately, 
and return as shown below. Index 0 will be considered even.

For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF']. See test cases for more examples.

The input will be a lowercase string with no spaces.

Good luck!

*/

//solution 1 
//using toupper
#include <string>
#include <utility>

std::pair<std::string, std::string> capitalize(const std::string &s)
{
	std::string strEven;
	std::string strOdd;
	for (int i = 0; i < s.length(); i++)
	{
		if (i%2==0)
		{
			strEven+=toupper(s[i]);
			strOdd+=s[i];
		}
		else
		{
			strEven+=s[i];
			strOdd+=toupper(s[i]);
		}
	}
    return {strEven, strOdd};
}

//solution 2
//using ASCII code
//A:65, a:97
//大小写字母相差32
#include <string>
#include <utility>

std::pair<std::string, std::string> capitalize(const std::string &s)
{
	std::string strEven;
	std::string strOdd;
	for (int i = 0; i < s.length(); i++)
	{
		if (i%2==0)
		{
			strEven+=s[i]-32;
			strOdd+=s[i];
		}
		else
		{
			strEven+=s[i];
			strOdd+=s[i]-32;
		}
	}
    return {strEven, strOdd};
}