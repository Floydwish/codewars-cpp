/*
14.Sum of Digits / Digital Root

Instructions

Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, 
continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

Examples
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/

//solution 1
//1.直接方式
//2.设定循环，并在结尾加上余数
//3.循环内部，若发现循环即将终止，则判断当前总和是否大于10
//4.若小于则返回，若大于则将总和重新赋值再次循环，直到总和小于10
int digital_root(int n)
{
    int res=0;
    while(n/10 != 0)
    {
        res+=n%10;
        n/=10;

        if (n/10 == 0 && (res+n%10)/10 !=0)
        {
            n=res+n%10;
            res=0;
        }
    }
    return res+n%10;
}


//solution 2
//1.直接方式优化,提取出计算每一次循环值的独立接口
//2.双重循环，只要循环值>=10,继续子循环，直到满足<10

//计算每一次循环后的值
int digital_num(int n)
{
    int res=0;
    while(n > 0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}

int digital_root(int n)
{
    while(n >= 10)
    {
        n = digital_num(n);
    }
    return n;
}


//solution 3
//Digital root is the remainder when you divide something with 9. 
//Example: 83%9=2 <- digital root is 2. 
//The only exception here is that when the remainder is zero, the digital root is 9, not 0. 
//So you need to substract 1 from the value before modulo and then add one afterwards so you never end up with 0. 
//Example2: 81%9=0 but 8+1=9. (81-1)%9=8 so (81-1)%9+1=9.

//1.数根 = n % 9
//2.避免结果为0，即像81这种情况,推出：数根 = (n-1) % 9 +1
int digital_root(int n) 
{
    return (n-1) % 9 + 1;
}