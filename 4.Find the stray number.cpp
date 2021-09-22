/*
4.Find the stray number
Instructions
You are given an odd-length array of integers, in which all of them are the same, except for one single number.

Complete the method which accepts such an array, and returns that single different number.

The input array will always be valid! (odd-length >= 3)

Examples
[1, 1, 2] ==> 2
[17, 17, 3, 17, 17, 17, 17] ==> 3

*/

//solution 1
//任何数与0异或，结果是本身
//相等的数异或，结果为0
//因此，所有数异或，相等的数互相消除，剩下单独的数
int stray(std::vector<int> numbers) 
{
    int num=0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        num~=numbers[i];
    }
    return num;
};


//solution 2
//先排序后比较
//排序后，要么在第一个，要么在最后一个
int stray(std::vector<int> numbers) 
{
   sort(numbers.begin(),numbers.end());
   return numbers[0]!=numbers[1]?numbers.front():numbers.back();
};