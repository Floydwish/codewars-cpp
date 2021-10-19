/*
13.Tidy Number (Special Numbers Series #9)

Instructions

Definition
A Tidy number is a number whose digits are in non-decreasing order.

Task
Given a number, Find if it is Tidy or not .


Notes
Number passed is always Positive .

Return the result as a Boolean

Input >> Output Examples
tidyNumber (12) ==> return (true)

Explanation:
The number's digits { 1 , 2 } are in non-Decreasing Order (i.e) 1 <= 2 .

tidyNumber (32) ==> return (false)
Explanation:
The Number's Digits { 3, 2} are not in non-Decreasing Order (i.e) 3 > 2 .

tidyNumber (1024) ==> return (false)
Explanation:
The Number's Digits {1 , 0, 2, 4} are not in non-Decreasing Order as 0 <= 1 .

tidyNumber (13579) ==> return (true)
Explanation:
The number's digits {1 , 3, 5, 7, 9} are in non-Decreasing Order .

tidyNumber (2335) ==> return (true)
Explanation:
The number's digits {2 , 3, 3, 5} are in non-Decreasing Order , Note 3 <= 3

ALL translations are welcomed
Enjoy Learning !!
Zizou

*/

//solution 1
//直观方法比较
#include <string>

using namespace std; 


bool tidyNumber (int number)
{
  int num=number;
  int numOne=num%10;
  int numTwo=0;
  while(num>=10)
  {
    num/=10;
    numTwo=num%10;
    if (numTwo>numOne)
    {
        return false;
    }
    else
    {
        numOne=numTwo;
    }
  }
  return true ;
}

//solution 2
//直观方法比较
//简化
#include <string>

using namespace std; 


bool tidyNumber (int number)
{
  int num=number;
  while(num>=10)
  {
    int last=num%10;
    num/=10;
    if (num%10 > last)
    {
        return false;
    }
  }
  return true ;
}


//solution 3
//使用标准库函数
//1.先转为string序列
//2.再判断是否已经是非递减状态is_sorted
#include <string>
#include <algorithm>

using namespace std; 


bool tidyNumber (int number)
{
  string convNum=to_string(number);
  return is_sorted(convNum.begin(),convNum.end());
}


//solution 4
//使用标准库函数
//1.先转为string序列
//2.再排序
//3.与原序列进行比较
#include <string>
#include <algorithm>

using namespace std; 


bool tidyNumber (int number)
{
  string convNum=to_string(number);
  sort(convNum.begin(),convNum.end());
  return convNum==to_string(number)?true:false;
}
