/*
15.Bit Counting

Instructions

Write a function that takes an integer as input, and returns the number of bits that are equal to one 
in the binary representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case

*/

//solution 1
//1.将定数转为2进制到思维方式
//2.除2取余,累加即可
unsigned int countBits(unsigned long long n)
{
  int count=0;
  while(n)
  {
    if (n%2==1)
    {
        count++;
    }
    n/=2;
  }
  return count;
}


//solution 2
//观念上优于solution 1
//1.将给定数直接视为2进制
//2.每次循环与1相与,结果累加
unsigned int countBits(unsigned long long n)
{
  int count=0;
  while(n)
  {
    count += n&1;
    n>>1;
  }
  return count;
}
