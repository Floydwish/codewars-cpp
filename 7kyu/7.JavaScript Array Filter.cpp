/*
7.JavaScript Array Filter

Instructions

The solution would work like the following:

get_even_numbers({2,4,5,6}) => {2,4,6}
*/


//solution 1
#include <vector>

std::vector<int> get_even_numbers(const std::vector<int>& arr) 
{
  int size=arr.size();
  std::vector<int> vec;
  for (int i = 0; i < size; ++i)
  {
      if (arr[i]%2==0)
      {
          vec.push_back(arr[i]);
      }
  }
  return vec;
}
