/*
10.Vowel Count

Instructions

Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.
*/

//solution 1
//直观解法
#include <string>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  for (int i = 0; i < inputStr.size(); ++i)
  {
      if (inputStr[i] == 'a' || inputStr[i] == 'e' ||inputStr[i] == 'i' ||inputStr[i] == 'o' ||inputStr[i] == 'u')
      {
          num_vowels+=1;
      }
  }
  return num_vowels;
}

//solution 2
//使用标准库算法cont_if
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int getCount(const string& inputStr){
  return count_if(inputStr.begin(),inputStr.end(),isVowel);
}



