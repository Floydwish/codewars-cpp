/*
9.Sum without highest and lowest number

Instructions
Sum all the numbers of the array (in F# and Haskell you get a list) except the highest and the lowest element (the value, not the index!).
(The highest/lowest element is respectively only one element at each edge, even if there are more than one with the same value!)

Example:

{ 6, 2, 1, 8, 10 } => 16
{ 1, 1, 11, 2, 3 } => 6

If array is empty, null or None, or if only 1 Element exists, return 0.
Note:In C++ instead null an empty vector is used. In C there is no null. ;-)
*/

#include <vector>
#include <algorithm>
using namespace std;


//solution 1
//使用标准库接口
int sum(vector<int> numbers)
{
    int max=*max_element(numbers.begin(),numbers.end());
    int min=*min_element(numbers.begin(),numbers.end());

    int sum=0;
    bool skipmax=false;
    bool skipmin=false;
    for (int i = 0; i < numbers.size(); ++i)
    {
    	if(skipmin==false && numbers[i]==min)
    	{
    		skipmin=true;
    		continue;
    	}
    	if (skipmax==false && numbers[i]==max)
    	{
    		skipmax=true;
    		continue;
    	}
    	sum+=numbers[i];
    }
    return sum;
}


//solution 2
//使用标准库算法接口
//相比solution 1作了逻辑上的简化
int sum(vector<int> numbers)
{
	if(numbers.size()<=2)
		return 0;
    int max=*max_element(numbers.begin(),numbers.end());
    int min=*min_element(numbers.begin(),numbers.end());

    int sum=0;
    for (int i = 0; i < numbers.size(); ++i)
    {
    	sum+=numbers[i];
    }
    return sum-max-min;
}

//solution 3
//使用标准库算法接口
//简化逻辑
int sum(vector<int> numbers)
{
	if(numbers.size()<=2)
		return 0;
	sort(numbers.begin(),numbers.end());

    int sum=0;
    for (int i = 1; i < numbers.size()-1; ++i)
    {
    	sum+=numbers[i];
    }
    return sum;
}


//solution 4
//时间复杂度最低
int sum(vector<int> numbers)
{
	if(numbers.size()<=2)
		return 0;

    int sum=0;
    int min=numbers[0];
    int max=numbers[0];
    for (int i = 0; i < numbers.size(); ++i)
    {
    	if(numbers[i]<min)
    		min=numbers[i];
    	else if (numbers[i]>max)
    	{
    		max=numbers[i];
    	}
    	sum+=numbers[i];
    }
    return sum-min-max;
}