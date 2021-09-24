 /*
Instructions

Introduction and Warm-up (Highly recommended)
Playing With Lists/Arrays Series

Task
Given an array of integers , Find the minimum sum which is obtained from summing each Two integers product .

Notes
Array/list will contain positives only .
Array/list will always has even size
Input >> Output Examples
minSum({5,4,2,3}) ==> return (22) 
Explanation:
The minimum sum obtained from summing each two integers product , 5*2 + 3*4 = 22

minSum({12,6,10,26,3,24}) ==> return (342)
Explanation:
The minimum sum obtained from summing each two integers product , 26*3 + 24*6 + 12*10 = 342

minSum({9,2,8,7,5,4,0,6}) ==> return (74)
Explanation:
The minimum sum obtained from summing each two integers product , 9*0 + 8*2 +7*4 +6*5 = 74

 */


#include <vector>

using namespace std;

int minSum (vector<int> passed)
{
  int sum=0;
  int size=passed.size();
  sort(passed.begin(),passed.end());
  for (int i = 0; i < size/2; ++i)
  {
      sum+=passed[i]*passed[size-1-i];
  }
  return sum ; 
}