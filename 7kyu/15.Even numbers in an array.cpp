/*
15.Even numbers in an array


Instructions

Given an array of digital numbers, return a new array of length number containing the last even numbers 
from the original array (in the same order). The original array will be not empty and will contain at least 
"number" even numbers.

For example:

([1, 2, 3, 4, 5, 6, 7, 8, 9], 3) => [4, 6, 8]
([-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26], 2) => [-8, 26]
([6, -25, 3, 7, 5, 5, 7, -3, 23], 1) => [6]
*/

//solution 1
//1.反向遍历，偶数则放置到vector中
//2.得到所有偶数后，翻转vector
#include <vector>
#include <algorithm>

std::vector<int> evenNumbers(std::vector<int> arr, int n) {
  std::vector<int> ret;
  for (int i = arr.size()-1; i >=0; --i)
  {
    if(arr[i]%2==0)
      ret.push_back(arr[i]);
    if (ret.size()==n)
    {
      std::reverse(ret.begin(),ret.end());
      break;
    }
  }
  return ret;
}