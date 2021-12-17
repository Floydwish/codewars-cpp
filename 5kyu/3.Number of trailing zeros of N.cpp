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
https://www.codewars.com/kata/52f787eb172a8b4ae1000a34/solutions/cpp
https://www.purplemath.com/modules/factzero.htm
https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function/





网上的关于该问题的说明：

You're probably reading this page because you've been assigned a seemingly impossible exercise, 
something along the lines of "Here's a really big number; consider its much bigger factorial and 
then figure out how many zeroes are at the end of the multiplied-out factorial."

This "trailing zeroes in a factorial" exercise is pretty easy to answer once you think about it the right way.
 I couldn't find anything much useful on the Internet, so here's a little lesson on how to handle it.

Find the number of trailing zeroes in the expansion of 23!
If I try to plug this into my calculator, I'll get something in scientific notation, 
because the answer is too big for the calculator to display. In practical terms, 
the calculator will show me the beginning of the number, and I'm only caring about 
the end of the number (the "trailing" part). So the calculator won't help. 
I'll try expanding the factorial:

1×2×3×4×5×6×7×8×9×10×11×12×13×14×15×16×17×18×19×20×21×22×23

Advertisement

I know that a number gets a zero at the end of it if the number has 10 as a factor. For instance,
 10 is a factor of 50, 120, and 1234567890. So I need to find out how many times 10 is a factor
  in the expansion of 23!.

But since 5×2 = 10, I need to account for all the products of 5 and 2. Looking at the factors 
in the above expansion, there are many more numbers that are multiples of 2 (2, 4, 6, 8, 10, 12, 14,...) 
than are multiples of 5 (5, 10, 15,...). That is, if I take all the numbers with 5 as a factor, 
I'll have way more than enough even numbers to pair with them to get factors of 10 
(and another trailing zero on my factorial). So to find the number of times 10 is a factor, 
all I really need to worry about is how many times 5 is a factor in all of the numbers between 1 and 23.
How many multiples of 5 are between 1 and 23? There is 5, 10, 15, and 20, for four multiples of 5.
 Paired with 2's from the even factors, this makes for four factors of 10, so:

23! has four trailing zeroes 





Find the number of trailing zeroes in 101!
Okay, how many multiples of 5 are there in the numbers from 1 to 101? There's 5, 10, 15, 20, 25,...

Oh, heck; let's do this the short way: 100 is the closest multiple of 5 below 101, and 100 ÷ 5 = 20, 
so there are twenty multiples of 5 between 1 and 101.

But wait: 25 is 5×5, so each multiple of 25 has an extra factor of 5 that I need to account for. 
How many multiples of 25 are between 1 and 101? Since 100 ÷ 25 = 4, there are four multiples of 25 
between 1 and 101.

Adding these, I get 20 + 4 = 24 trailing zeroes in 101!



This reasoning extends to working with larger numbers.

Find the number of trailing zeroes in the expansion of 1000!
Okay, there are 1000 ÷ 5 = 200 multiples of 5 between 1 and 1000. The next power of 5, namely 25, 
has 1000 ÷ 25 = 40 multiples between 1 and 1000. The next power of 5, namely 125, will also fit 
in the expansion, and has 1000 ÷ 125 = 8 multiples between 1 and 1000. The next power of 5, 
namely 625, also fits in the expansion, and has 1000 ÷ 625 = 1.6... um, okay, 625 has 1 multiple 
between 1 and 1000. (I don't care about the 0.6 "multiples", only the one full multiple, 
so I truncate my division down to a whole number.)

In total, I have 200 + 40 + 8 + 1 = 249 copies of the factor 5 in the expansion, and thus:
249 trailing zeroes in the expansion of 1000!




The previous example highlights the general method for answering this question, no matter what 
factorial they give you.

Take the number that you've been given the factorial of.
Divide by 5; if you get a decimal, truncate to a whole number.
Divide by 52 = 25; if you get a decimal, truncate to a whole number.
Divide by 53 = 125; if you get a decimal, truncate to a whole number.
Continue with ever-higher powers of 5, until your division results in a number less than 1. 
Once the division is less than 1, stop.
Sum all the whole numbers you got in your divisions. This is the number of trailing zeroes.


Here's how the process works:

How many trailing zeroes would be found in 4617!, upon expansion?
I'll apply the procedure from above:

51 :  4617 ÷ 5 = 923.4, so I get 923 factors of 5
52 :  4617 ÷ 25 = 184.68, so I get 184 additional factors of 5
53 :  4617 ÷ 125 = 36.936, so I get 36 additional factors of 5
54 :  4617 ÷ 625 = 7.3872, so I get 7 additional factors of 5
55 :  4617 ÷ 3125 = 1.47744, so I get 1 more factor of 5
56 :  4617 ÷ 15625 = 0.295488, which is less than 1, so I stop here.
Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.

By the way, you can get the same result, 
if you keep track as you go, by just dividing repeatedly in your calculator by 5's: 
4617 ÷ 5 = 923.4 (write down 923), 923.4 ÷ 5 = 184.68 (write down 184), 
184.68 ÷ 5 = 36.936 (write down 36), 36.936 ÷ 5 = 7.3827 (write down 7), 
7.3827 ÷ 5 = 1.47744 (write down 1), and 1.47744 ÷ 5 is goint to be less than 1,
 so you're done. Turn to your scratch paper were you've written down the whole numbers, 
 and sum them to get 1151.

*/


//solution 1
//算数推演：
//1.经过推算，当数字是5或5的倍数时，0的个数每次+1（如5,10,15,20）
//2.当数字是5的n次方时(n>1,如5^2=25,5^3=125),0的个数额外再+1

//代码实现：
//1.计算出给定数的5的最大次方值，该值即为最大边界值
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


//solution 2
//solution 1 优化
//1.以1为初值，*5为步进，边界为给定值
//2.使用给定值除以每次循环值(如5^1,5^2,5^3...)，累加结果即为尾部为0的总数
long zeros(long n) 
{
  long num = 1;
  long cnt = 0;
  while(num <= n)
  {
     num *=5;
     cnt += n/num;
  }
  return cnt;
}




//solution 3
//1.每次循环 n/=5,(效果与每次循环使用n/(5^1),n/(5^2),n/(5^3)...相同)
//2.结果累加,直到n为0退出循环
long zeros(long n) 
{
  long cnt = 0;
  while(n)
  {
    cnt += n/=5;
  }
}









