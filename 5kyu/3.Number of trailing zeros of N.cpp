/*
3.Number of trailing zeros of N!

Instructions

Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 * ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros
Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.

资料：
https://www.purplemath.com/modules/factzero.htm



*/

//solution 1
//算数推演：
//1.经过推算，当数字是5或5的倍数时，0的个数每次+1（如5,10,15,20）
//2.当数字是5的n次方时(n>1,如5^2=25,5^3=125),0的个数额外再+1

//代码实现：
//1.计算出给定数的最大5的次方值，该值即为最大边界值
//2.以5为初值，*5为步进，边界为第1步的最大边界值
//3.使用给定值除以每次循环值(如5^1,5^2,5^3...)，累加结果即为尾部为0的总数
long zeros(long n) 
{
  long num = 1;
  while(num <= n)
  {
     num *=5;
  }
  long cnt = 0;
  for (int i = 5; i <= num; i*=5)
  {
      cnt += n/i;
  }
  return cnt;
}









