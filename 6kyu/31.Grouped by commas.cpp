/*
31.Grouped by commas

Instructions

Finish the solution so that it takes an input n (integer) and returns a string that is the decimal representation of the number 
grouped by commas after every 3 digits.

Assume: 0 <= n < 2147483647

Examples
       1  ->           "1"
      10  ->          "10"
     100  ->         "100"
    1000  ->       "1,000"
   10000  ->      "10,000"
  100000  ->     "100,000"
 1000000  ->   "1,000,000"
35235235  ->  "35,235,235"






*/

//solution 1
//1.循环除
//2.计数，每三位添加1个','
//3.翻转结果
#include <string>
#include <algorithm>

using namespace std;

std::string group_by_commas(int n)
{
       if (n==0)
       {
              ret.push_back('0');
       }
       string ret;
       int count =0;
       while (n)
       {
              if (count==3)
              {
                     ret.push_back(',');
                     count=0;
              }
              else
              {
                     if (n%10)
                     {
                            char c[1];
                            //itoa(n%10,c,10);
                            sprintf(c,"%d",n%10);
                            ret.push_back(c[0]);
                     }
                     else
                     {
                            ret.push_back('0');
                     }
                     
                     n/=10;
                     count++;
              }

       }
       if (ret.size()>1)
       {
              reverse(ret.begin(),ret.end());
       }
       
       return ret;
}


//solution 2
//1.将int转为string(C++ 14, VS2019, VS2010为C++10,不支持)
//2.循环从后往前遍历string,每3个位置插入一个','
//3.当剩余字符<=3时，停止循环，返回结果
#include <string>

using namespace std;

std::string group_by_commas(int n)
{
    string str = to_string(n);

    for (int i = str.size(); i > 3;)
    {
        i -= 3;
        str.insert(i,",");
        //10000
    }
    return str;
}
