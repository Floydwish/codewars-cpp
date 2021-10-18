/*
12.Sum of two lowest positive integers

Instructions

Create a function that returns the sum of the two lowest positive numbers given an array of 
minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.

*/
//solution 1
//直观算法
//1.设定初值为int类型最大值0x7FFFFFF
//2.新值小于最小值时，将最小值赋值给次小值，将新值赋值给最小值
//3.否则，新值大于最小值，小于次小值时，将新值赋值给次小值
//4.返回时要转为long,否则会溢出

#include <vector>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    int minOne=0x7FFFFFFF;
    int minTwo=0x7FFFFFFF;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i]<minOne)
        {
            minTwo=minOne;
            minOne=numbers[i];
        }
        else if (numbers[i]<minTwo)
        {
            minTwo=numbers[i];
        }

    }
    return (long)minOne+(long)minTwo;
}

//solution 2
//1.使用标准库排序算法
//2.递增排序后，返回前两个值的和

#include <vector>
#include <algorithm>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::vector<int> num(numbers);
    std::sort(num.begin(),num.end());

    return num[0]+num[1];
}