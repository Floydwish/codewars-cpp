/*
17.Create Phone Number

Instructions

Write a function that accepts an array of 10 integers (between 0 and 9), 
that returns a string of those numbers in the form of a phone number.

Example
createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"
The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses!

*/


//solution 1
//1.循环添加字符
//2.int数字转对应字符：i + '0'
//字符转对应数字: i - '0'
#include <string>

using namespace std;

std::string createPhoneNumber(const int arr[10])
{
    string res;
    for (int i = 0; i < 10; ++i)
    {
        res.push_back(arr[i] + '0');
        if (i == 0)
        {
            res.insert(i, 1, '(');
        }
        else if (i == 2)
        {
            res.insert(i+2,1,')');
            res.insert(i+3,1,' ');

        }
        else if (i == 5)
        {
            res.insert(i+4,1,'-');
        }
    }
    return res;
}

//solution 2
//1.sprintf格式化
#include <string>
#include <stdio.h>
std::string createPhoneNumber(const int arr[10])
{
    char buf[15] = { 0 };
    sprintf(buf,sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
    return buf;
}

//solution 3
//1.根据结果格式,构造对应string
//2.将string中待确定字符,通arr数组中字符一一对应
//3.int数字转对应字符：i + '0'
//字符转对应数字: i - '0'
#include <string>

std::string createPhoneNumber(const int arr[10])
{
    std::string ret = "(***) ***-****";
    int index = 0;
    for (int i = 0; i < ret.length(); i++)
    {
        if (ret[i]=='*')
        {
            ret[i] = arr[index] + '0';
            index++;
        }
    }
    return ret;
}