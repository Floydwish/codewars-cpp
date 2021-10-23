/*
17.Sum of numbers from 0 to N

Description:

We want to generate a function that computes the series starting from 0 and 
ending until the given number.

Example:
Input:

> 6
Output:

0+1+2+3+4+5+6 = 21

Input:

> -15
Output:

-15<0

Input:

> 0
Output:

0=0
*/

//solution 1
//直觉算法
//1.处理特殊情况
//2.循环累加
//3.同时循环创建输出序列
//4.输出构造string
#include <string>

using namespace std;

class SequenceSum
{
  int count;
  
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence(){
    if (count<0)
    {
    	return to_string(count)+"<0";
    }
    else if (count==0)
    {
    	return "0=0";
    }
    else
    {
    	string res("0");
    	long result=0;
    	for (int i = 1; i <= count; ++i)
    	{
    		result+=i;
    		res+=("+"+to_string(i));
    	}
    	return res+" = "+to_string(result);

    }
}

SequenceSum::SequenceSum (int c) {
  count = c;
}

//solution 2
//高斯算法
//1.处理特殊情况
//2.循环构造输出序列
//3.高斯算法计算总和
//4.输出结果

#include <string>

using namespace std;

class SequenceSum
{
  int count;
  
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence(){
    if (count<0)
    {
    	return to_string(count)+"<0";
    }
    else if (count==0)
    {
    	return "0=0";
    }
    else
    {
    	string res("0");
    	for (int i = 1; i <= count; ++i)
    	{
    		res+=("+"+to_string(i));
    	}
    	return res+" = "+to_string(count*(1+count)/2);

    }
}

SequenceSum::SequenceSum (int c) {
  count = c;
}