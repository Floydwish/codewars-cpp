/*
28.Backspaces in string

Instructions

Assume "#" is like a backspace in string. This means that string "a#bc#d" actually is "bd"

Your task is to process a string with "#" symbols.

Examples
"abc#d##c"      ==>  "ac"
"abc##d######"  ==>  ""
"#######"       ==>  ""
""              ==>  ""
*/

//solution 1
//1.从后往前遍历string
//2.若遇到#则计数，往前遍历时，跳过#个数的字符
//3.将结果string反转
#include <string>
#include <algorithm>    //reverse()
using namespace std;

std::string cleanString(const std::string &s)
{
    string str;
    int count=0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            count++;
        }
        else
        {
            if (count>0)
            {
                count--;
                continue;
            }
            else
            {
                str.push_back(s[i]);
            }
        }
    }
    reverse(str.begin(),str.end());
    return str;
}


//solutin 2
//1.从前往后遍历string
//2.若字符非#，则拷贝到结果string中
//3.否则，将最后一个字符删除
//4.注意：删除前先判断string大小，否则将导致未定义行为
#include <string>
using namespace std;

std::string cleanString(const std::string &s)
{
    string str;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != '#')
        {
            str.push_back(s[i]);
        }
        else if(str.size()>0)   
        {
            str.pop_back();  //注意先判断结果string 要不为空
                            //If the string is empty, it causes undefined behavior
        }
    }
    return str;
}