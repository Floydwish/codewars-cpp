/*
1.Binary Addition
Instructions

Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before,
 or after the addition.

The binary number returned should be a string.

Examples:

add_binary(1, 1) == "10" (1 + 1 = 2 in decimal or 10 in binary)
add_binary(5, 9) == "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/


//solution 1
#include <cstdint>
#include <string>
#include <algorithm>

std::string add_binary(uint64_t a, uint64_t b) {
	uint64_t sum=a+b;
	if (0==sum)
		return "0";
	std::vector<uint64_t> vec;
	std::string str;
	while(sum)
	{
		uint64_t tmp=sum%2;
		vec.push_back(tmp);
		sum/=2;
	}
	int si=vec.size();
	while (si--)
	{
		str.push_back('0'+vec[si]);
	}
	return str;
}


//solution 2
std::string add_binary(uint64_t a, uint64_t b) {
	a+=b;			//1.节省空间
	std::string str;
	do				//2.特殊值0，顺便就处理了
	{
		str=std::to_string(a%2)+str; //3.除2取余法与反转字串结合
		a/=2;
	} while (a);
	return str;
}
