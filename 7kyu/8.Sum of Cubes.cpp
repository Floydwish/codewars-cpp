/*
8.Sum of Cubes

Instructions

Write a function that takes a positive integer n, sums all the cubed values from 1 to n, and returns that sum.

Assume that the input n will always be a positive integer.

Examples: (Input --> output)

2 --> 9 (sum of the cubes of 1 and 2 is 1 + 8)
3 --> 36 (sum of the cubes of 1, 2, and 3 is 1 + 8 + 27)


unsigned int sum_cubes(unsigned int n)
{
  return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}


*/

//solution 1
//直观计算
unsigned int sum_cubes(unsigned int n) 
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i*i*i;
    }  
    return sum;
}



//solution 2
//使用pow函数
#include <math.h>
unsigned int sum_cubes(unsigned int n) 
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=pow(i,3);
    }  
    return sum;
}

//solution 3
//观察规律
//n=2时，结果为3^2,而3是累加的和; n=3时，结果为8^2，8也是累加的和
//合理归纳为，结果为累加和的平方
//累加的和又可以用高斯算法计算
//得出下面的解法，时间复杂度和空间复杂度优于上面的解法
unsigned int sum_cubes(unsigned int n) 
{
    return (n*(n+1)/2)*(n*(n+1)/2);
}





