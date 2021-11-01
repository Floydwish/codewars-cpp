/*
3.Count characters in your string

Instructions

The main idea is to count all the occurring characters in a string. If you have a string like aba,
 then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.
*/


//solution 1
//1.查找map中是否已存在字符
//2.未存在则赋初值为1，存在则数量+1
#include <map>
#include <string>

using namespace std;

std::map<char, unsigned> count(const std::string& str) 
{
    map<char,unsigned> ma;
    for (int i = 0; i < str.size(); ++i)
    {
        if (ma.find(str[i]) == ma.end())
        {
            ma[str[i]] = 1;
        }
        else
            ma[str[i]] += 1;
    }
    return ma;
}


//solution 2
//1.循环计数
//2.使用[]运算符，若无则默认为0，若有则得到value,每次+1即可

#include <map>
#include <string>

using namespace std;

std::map<char, unsigned> count(const std::string& str) 
{
    map<char,unsigned> ma;
    for (int i = 0; i < str.size(); ++i)
    {
        ma[str[i]]++;
    }
    return ma;
}