/*
7.Simple string expansion

Instructions

Consider the following expansion:

solve("3(ab)") = "ababab"     -- because "ab" repeats 3 times
solve("2(a3(b))") = "abbbabbb" -- because "a3(b)" == "abbb", which repeats twice.
Given a string, return the expansion of that string.

Input will consist of only lowercase letters and numbers (1 to 9) in valid parenthesis. 
There will be no letters or numbers after the last closing parenthesis.

More examples in test cases.

Good luck!

Please also try Simple time difference


Describe(Simple_string_expansion)
{
    It(Example_tests)
    {
        Assert::That(solve("3(ab)"), Equals("ababab"));
        Assert::That(solve("2(a3(b))"),Equals("abbbabbb"));
        Assert::That(solve("3(b(2(c)))"),Equals("bccbccbcc"));
        Assert::That(solve("k(a3(b(a2(c))))"),Equals("kabaccbaccbacc"));
   
    }
}; 



*/

//solution 0
//1.提取出repeat函数,用于扩展字符串
//2.从后往前循环遍历,记录下

#include <string>

using namespace std;


string repeat(string str,int count)
{
    string ret;
    for (int i = 0; i < count; i++)
    {
        ret += str;
    }
    return ret;
}

std::string solve(std::string s)
{
    string str(s);
    int left = 0;
    int right = 0;
    string ch = "";
    string cur = "";
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] == ')')
            right++;
        else if (s[i] == '(')
            left++;
        else if (isalpha(s[i]))
            ch += s[i];
        else if (isdigit(s[i]))
        {
            int tmp = int(s[i]-'0');
            cur = repeat(ch, tmp);
            ch = cur;
        }
    }
    reverse(ch.begin(), ch.end());
    return ch;
}



//solution 1
//1.提取出repeat函数,用于扩展字符串
//2.从后往前循环遍历,遇到字符时,保存到临时string
//3.遇到数字时,扩展该临时string,将扩展结果作为临时string,依次类推
//4.最后将string反转后返回

#include <string>

using namespace std;


string repeat(string str,int count)
{
    string ret;
    for (int i = 0; i < count; i++)
    {
        ret += str;
    }
    return ret;
}

std::string solve(std::string s)
{
    string str(s);
    string ch = "";
    string cur = "";
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (isalpha(s[i]))
            ch += s[i];
        else if (isdigit(s[i]))
        {
            int tmp = int(s[i]-'0');
            cur = repeat(ch, tmp);
            ch = cur;
        }
    }
    return string(ch.rbegin(),ch.rend());
}
