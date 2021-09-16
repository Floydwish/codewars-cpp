/*
10.MakeUpperCase

Instructions
Write a function which converts the input string to uppercase.
*/


//solution 1
#include <string>

std::string makeUpperCase (const std::string& input_str)
{
	std::string str=input_str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]>=97 && str[i]<=122)
		{
			str[i]-=32;
		}
	}
	return str;
}

//solution 2
//使用toupper
#include <string>

std::string makeUpperCase (const std::string& input_str)
{
	std::string str;
	for (int i = 0; i < input_str.size(); ++i)
	{
		str += toupper(input_str[i]);
	}
	return str;
}

//solution 3
//使用toupper
#include <string>

std::string makeUpperCase (const std::string& input_str)
{
	std::string str;
	for (int i = 0; i < input_str.size(); ++i)
	{
		str.push_back(toupper(input_str[i]));
	}
	return str;
}