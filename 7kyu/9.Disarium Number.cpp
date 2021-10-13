/*
9.Disarium Number (Special Numbers Series #3)

Instructions

Definition
Disarium number is the number that The sum of its digits powered with their respective positions 
is equal to the number itself.

Task
Given a number, Find if it is Disarium or not .


Notes
Number passed is always Positive .
Return the result as String

Input >> Output Examples

disariumNumber(89) ==> return "Disarium !!"
Explanation:
Since , 8^1 + 9^2 = 89 , thus output is "Disarium !!"

disariumNumber(564) ==> return "Not !!"
Explanation:
Since , 5^1 + 6^2 + 4^3 = 105 != 564 , thus output is "Not !!"
*/

//solution 1
//1.获取数字的位数
//2.逐位求值并相加
#include <string>
#include <math.h>

using namespace std; 

string disariumNumber (int number )
{
    int sum=0;
    int num=number;
    int count=1+log10((double)num);
    
    while(num%10)
    {
        sum+=pow((double)(num%10),count);
        count--;
        num/=10;
    }
    if (sum==number)
    {
        return "Disarium !!";
    }
    return "Not !!";
}