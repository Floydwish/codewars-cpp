/*
43.Basics 03: Strings, Numbers and Calculation

Instructions

Here you have to do some mathematical operations on a "dirty string". 
This kata checks some basics, it's not too difficult.

So what to do?

Input: String which consists of two positive numbers (doubles) and 
exactly one operator like +, -, * or / always between these numbers. 
The string is dirty, which means that there are different characters inside too, 
not only numbers and the operator. You have to combine all digits left and right, 
perhaps with "." inside (doubles), and to calculate the result which has to be rounded to an integer and 
converted to a string at the end.

Easy example:
Input: "gdfgdf234dg54gf*23oP42"
Output: "54929268" (because 23454*2342=54929268)
First there are some static tests, later on random tests too...

*/


//solution 1
//1.提取左右操作数和符号
//2.根据符号进行计算
//3.处理成符合要求的值,如round
#include <string> 
#include <sstream>
#include <math.h>

using namespace std;

std::string calculateString(std::string calcIt)
{
    //"gdfgdf234dg54gf*23oP42"
    std::string result = "";
    string str;
    double left = 0;
    double right = 0;
    char sign;
    ostringstream ostr;
    for (int i = 0; i < calcIt.size(); ++i)
    {
        if (calcIt[i] == '.' || isdigit(calcIt[i]))
        {
            str.push_back(calcIt[i]);
        }
        else if (calcIt[i] == '+' || calcIt[i] == '-' || calcIt[i] == '*' || calcIt[i] == '/')
        {
            left = stod(str.c_str());

            str.clear();
            sign = calcIt[i];
        }
    }
    right = stod(str.c_str());
    double ret;
    if (sign == '+')
    {
        ret = round(left + right);
        ostr << ret;
        result = ostr.str();
    }
    else if (sign == '-')
    {
        ret = round(left - right);
        ostr << ret;
        result = ostr.str();
    }
    else if (sign == '*')
    {
        ret = round(left * right);
        long rtn;

        if ((long)ret == ret)
        {
            rtn = (long)ret;
            ostr << rtn;
        }
        else
            ostr << ret;
        result = ostr.str();
    }
    else if (sign == '/')
    {
        ret = round(left / right);
        ostr << ret;
        result = ostr.str();
    }
    return result;
}


//solution 2
//1.提取左右操作数和符号
//2.根据符号进行计算
//3.处理成符合要求的值,如round
#include <string> 
#include <math.h>

using namespace std;

std::string calculateString(std::string calcIt)
{
    std::string result = "";
    string str;
    double left = 0;
    double right = 0;
    char sign;
    ostringstream ostr;
    for (int i = 0; i < calcIt.size(); ++i)
    {
        if (calcIt[i] == '.' || isdigit(calcIt[i]))
        {
            str.push_back(calcIt[i]);
        }
        else if (calcIt[i] == '+' || calcIt[i] == '-' || calcIt[i] == '*' || calcIt[i] == '/')
        {
            left = stod(str.c_str());

            str.clear();
            sign = calcIt[i];
        }
    }
    right = stod(str.c_str());


    double ret;
    if (sign == '+')            return to_string(int(round(left + right)));
    else if (sign == '-')       return to_string(int(round(left - right)));
    else if (sign == '*')       return to_string(int(round(left * right)));
    else if (sign == '/')       return to_string(int(round(left / right)));

}

