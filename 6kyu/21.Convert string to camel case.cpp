/*
21.Convert string to camel case

Instructions

Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
The first word within the output should be capitalized only if the original word was capitalized 
(known as Upper Camel Case, also often referred to as Pascal case).

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
*/


//solution 1
//1.遍历string
//2.若出现非字母的字符，删除该字符，并将后一个字符转为大写(删除后，后一个字符前进了一位，因此将当前字符转为大写即可)
//3.返回结果字符
#include <string>
using namespace std;

std::string to_camel_case(std::string text) 
{
    string res(text);
    for (int i = 0; i < res.size(); ++i)
    {
        if (!isalpha(res[i]))
        {
            res.erase(i,1);
            res [i] = toupper(res[i]);
        }
    }
    return res;
}


//solution 2
//较solution 1更准确符合题意
//1.遍历string
//2.若出现非字母的字符，删除该字符，并将后一个字符转为大写(删除后，后一个字符前进了一位，因此将当前字符转为大写即可)
//3.返回结果字符

std::string to_camel_case(std::string text) 
{
    string res(text);
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i] == '-' || res[i] == '_')
        {
            res.erase(i,1);
            res [i] = toupper(res[i]);
        }
    }
    return res;
}


