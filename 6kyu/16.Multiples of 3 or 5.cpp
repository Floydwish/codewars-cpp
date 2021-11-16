/*
16.Multiples of 3 or 5

Instructions

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in. 
Additionally, if the number is negative, return 0 (for languages that do have them).

Note: If the number is a multiple of both 3 and 5, only count it once.

Courtesy of projecteuler.net (Problem 1)

*/

//solution 1
//反向循环法
int solution(int number) 
{
    int sum=0;
    while(number-->=3)
    {
        if (number%3==0 || number%5==0)
        {
            sum+=number;
        }
    }
    return sum;

}

//solution 2
//正向循环法
int solution(int number) 
{
    int sum=0;
    for (int i = 3; i < number; ++i)
    {

        if (i%3==0 || i%5==0)
        {
            sum+=i;
        }
    }
    return sum;

}