/*
41.Simple Simple Simple String Expansion

Instructions

Given a string that includes alphanumeric characters ('3a4B2d') return
the expansion of that string: The numeric values represent the occurrence of
 each letter preceding that numeric value. There should be no numeric characters 
 in the final string. Empty strings should return an empty string.

The first occurrence of a numeric value should be the number of times each character 
behind it is repeated, until the next numeric value appears.

string_expansion('3D2a5d2f') == 'DDDaadddddff'
string_expansion('3abc') == 'aaabbbccc'       # correct
string_expansion('3abc') != 'aaabc'           # wrong
string_expansion('3abc') != 'abcabcabc'       # wrong
If there are two consecutive numeric characters the first one is ignored.

string_expansion('3d332f2a') == 'dddffaa'
If there are two consecutive alphabetic characters then the first character 
has no effect on the one after it.

string_expansion('abcde') == 'abcde'
Your code should be able to work for both lower and capital case letters.

string_expansion('') == ''
*/


//solution 1
//1.循环判断,记录数字,构造结果字串
//2.最少复制一次,即无数字的情况应返回原字符
#include <string>

using namespace std;

std::string string_expansion(const std::string& s) {
    string ret;
    int num = 1;
    int i;
    for (i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            num = atoi(&s[i]);
        }
        else
        {
            for (int j = 0; j < num; ++j)
            {
                ret.push_back(s[i]);
            }
        }
    }
    return ret;
}


//solution 2
//1.solution 1优化
//2.使用num=s[i]-'0'替代atoi 计算字母扩展次数
//3.使用string construct 替代循环push_back,优化性能
#include <string>

using namespace std;

std::string string_expansion(const std::string& s) {
    string ret;
    int num=1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            num=s[i]-'0';
        }
        else
        {
            ret += string(num,s[i]);    //string construct
        }
    }
    return ret;
}