/*
27.Is a number prime?

Instructions

Define a function that takes one integer argument and returns logical value true or false 
depending on if the integer is a prime.

Per Wikipedia, a prime number (or a prime) is a natural number greater than 1 that has no positive divisors 
other than 1 and itself.

Requirements
You can assume you will be given an integer input.
You can not assume that the integer will be only positive. You may be given negative numbers as well (or 0).
NOTE on performance: There are no fancy optimizations required, but still the most trivial solutions might time out. 
Numbers go up to 2^31 (or similar, depends on language version). Looping all the way up to n, or n/2, will be too slow.
Example
is_prime(1)   false 
is_prime(2)   true  
is_prime(-1)  false 

*/

//solution 1
//1.质数：大于1的自然数中，除了1和它本身以外不再有其他因数，这样的数称为质数
//2.必须是大于1的自然数，此条件作为特殊情况判断
//3.循环检查是否能被整除，关键在如何缩小范围
//4.使用sqrt即开平方得出平方根，检查从2~sqrt(num)范围即可
bool isPrime(int num) {
  if (num <= 1)
  {
      return false;
  }

  for (int i = 2; i <= sqrt(num); ++i)
  {
      if (num %i ==0)
      {
          return false;
      }
  }
  return true;
}

