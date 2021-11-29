/*
22.Does my number look big in this?

Instructions

A Narcissistic Number is a positive number which is the sum of its own digits, 
each raised to the power of the number of digits in a given base. In this Kata, 
we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits), which is narcisstic:

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

and 1652 (4 digits), which isn't:

    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a 
Narcissistic number in base 10. This may be True and False in your language, e.g. PHP.

Error checking for text strings or other invalid inputs is not required, only valid positive non-zero 
integers will be passed into the function.

*/

//solution 1
//1.将给定数字转换成string
//2.根据string的长度作为幂，并进行for循环
//3.调用pow进行幂运算，并累加
//4.累加结果与给定数字比较，返回比对结果
#include <string>
#include <math.h>

using namespace std;

bool narcissistic(int value)
{
    long sum = 0;
    string str = to_string(value);
    int count = str.length();

    for (int i = 0; i < count; ++i)
    {
        sum += pow((int)str[i]-48, count);  //注意ASCII码与数字差别
    }
    return value == sum ? true : false;
}



//solution 2
//0.solution 1优化版
//1.将给定数字转换成string
//2.根据string的长度作为幂，并进行for循环
//3.调用pow进行幂运算，并累加
//4.累加结果与给定数字比较，返回比对结果
#include <string>
#include <math.h>

using namespace std;

bool narcissistic(int value)
{
    long sum = 0;
    string str = to_string(value);
    int count = str.length();

    for (int i = 0; i < count; ++i)
    {
        sum += pow(str[i]-48, count);   //str[i]返回ASCII值，差值即为数字
    }
    return value == sum; //比较结果直接返回
}


//solution 3
//1.使用math标准库中的log10获取给定数字的位数
//2.在循环中进行计算，从低位到高位累加
//3.累加结果与给定数字比较，返回比对结果
#include <string>
#include <math.h>

using namespace std;

bool narcissistic(int value)
{
    int n = value;
    long sum = 0;
    int count = log10(n)+1;

    while(n)
    {
        sum += pow(n%10,count);
        n/=10;
    }
    return value == sum; //比较结果直接返回
}