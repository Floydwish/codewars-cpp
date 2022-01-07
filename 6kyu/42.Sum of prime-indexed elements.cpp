/*

42.Sum of prime-indexed elements

Instructions

In this Kata, you will be given an integer array and your task is to return 
the sum of elements occupying prime-numbered indices.

The first element of the array is at index 0.

Good luck!


test：
Describe(Sum_of_prime_indexed_elements)
{
    It(Example_tests)
    {
        Assert::That(solve(std::vector<int>{}), Equals(0));
        Assert::That(solve(std::vector<int>{1,2,3,4}),Equals(7));
        Assert::That(solve(std::vector<int>{1,2,3,4,5,6}),Equals(13));
        Assert::That(solve(std::vector<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}),Equals(47));
   
    }
}; 


说明：
质数又称“素数”，是指只有1和它本身两个正因数的自然数。 
100以内质数：2、3、5、7、11、13、17、19、23、29、31、37、41、43、47、53、59、61、67、71、73、79、83、89、97，共计25个

*/


//solution 1
//1.提取判断下标是否为质数的接口isPrimeNum
//2.循环判断,下标为质数则累加,否则忽略
//3.质数的判断从2开始,即循环从2开始
bool isPrimeNum(int n)
{
    for (int i = 2; i < n-1; ++i)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int solve(std::vector<int> v){
  
  int sum=0;
  for (int i = 2; i < v.size(); ++i)
  {
      if (isPrimeNum(i))
      {
          sum+=v[i];
      }
  }
  return sum;

}