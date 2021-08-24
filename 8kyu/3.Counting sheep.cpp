//3.Counting sheep

/*
Consider an array/list of sheep where some sheep may be missing from their place. We need a function that counts the number of sheep present in the array (true means present).

For example,

[true,  true,  true,  false,
  true,  true,  true,  true ,
  true,  false, true,  false,
  true,  false, false, true ,
  true,  true,  true,  true ,
  false, false, true,  true]
The correct answer would be 17.

Hint: Don't forget to check for bad values like null/undefined
*/

/*solution1*/
#include <vector>

using namespace std; 

int count_sheep(vector<bool> arr) 
{
   int count=0;
  for(int i=0;i<arr.size();i++)
  {
    if (arr[i]==true)
    {
      count++;
    }
  }
  return count;
}

/*solution2*/
#include <vector>
#include <algorithm>

using namespace std; 

int count_sheep(vector<bool> arr) 
{
  return count(arr.begin(),arr.end(),true);
}


/*solution3*/
#include <vector>
#include <algorithm>
using namespace std; 

int count_sheep(vector<bool> arr) 
{
  return count(arr.cbegin(),arr.cend(),true);
}

/*
question:
What is the difference between cbegin, begin and cend, end?
and why are the "c"-ones preffered here?

answer:
cbegin() returns always returns a const_iterator unconditionally, 
but begin() returns a const_iterator or an iterator depending if the vector (in this example) is const or not
*/


