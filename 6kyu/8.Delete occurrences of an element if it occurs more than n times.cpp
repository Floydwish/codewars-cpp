/*
8.Delete occurrences of an element if it occurs more than n times

Instructions

Enough is enough!

Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, 
and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, 
since the motive usually repeats. He isn't fond of seeing the Eiffel tower 40 times. He tells them that 
he will only sit during the session if they show the same motive at most N times. Luckily, Alice and 
Bob are able to encode the motive as a number. Can you help them to remove numbers such that their list 
contains each number only up to N times, without changing the order?

Task
Given a list lst and a number N, create a new list that contains each number of lst at most N times without 
reordering. For example if N = 2, and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] 
since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].

Example
  delete_nth ([1,1,1,1],2) # return [1,1]
  
  delete_nth ([20,37,20,21],1) # return [20,37,21]
*/


//solution 1
//1.遍历法
//2.每此遍历计算当前元素到个数，若小于规定数则收入，否则丢弃
#include <vector>

using namespace std;

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  vector<int> vec;
  for (int i = 0; i < arr.size(); ++i)
  {
      if (count(vec.begin(),vec.end(),arr[i]) < n)
      {
          vec.push_back(arr[i]);
      }
  }
  return vec;

}

//solution 2
//1.遍历法+map
//2.每此遍历时先在map中查找是否小于规定数，若小于规定数则收入，否则丢弃
#include <vector>
#include <unordered_map>

using namespace std;

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  vector<int> vec;
  unordered_map<int,int> map;
  for (int i = 0; i < arr.size(); ++i)
  {
      if (map[arr[i]]++ < n)
      {
          vec.push_back(arr[i]);
      }
  }
  return vec;

}