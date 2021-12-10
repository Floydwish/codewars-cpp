/*
30.Consonant value

Instructions

Given a lowercase string that has alphabetic characters only and no spaces, 
return the highest value of consonant substrings. Consonants are any letters of the alphabet except "aeiou".

We shall assign the following values: a = 1, b = 2, c = 3, .... z = 26.

For example, for the word "zodiacs", let's cross out the vowels. We get: "z o d ia cs"

-- The consonant substrings are: "z", "d" and "cs" and the values are z = 26, d = 4 and cs = 3 + 19 = 22. The highest is 26.
solve("zodiacs") = 26

For the word "strength", solve("strength") = 57
-- The consonant substrings are: "str" and "ngth" with values "str" = 19 + 20 + 18 = 57 and "ngth" = 14 + 7 + 20 + 8 = 49. 
The highest is 57.
For C: do not mutate input.

More examples in test cases. Good luck!

思路分析：
1.循环计算、不断更新最大值

*/



//solution 1
//0.使用string放置元音字母
//1.循环计算
//2.未遇到元音字母时累加，遇到元音字母后，将累加值与最大值比较，决定去留
//3.循环结束后，再比较累加值和最大值，取较大者返回(最后一次的累加值，会因循环结束而未比较)
#include <string>
using namespace std;

int solve(const std::string &s)
{
    string str("aeiou");
    int max = 0;
    int current = 0;
    int j = str.find(s[0]);
    j = str.find(s[1]);
    for (int i = 0; i < s.size(); ++i)
    {
        if (string::npos != str.find(s[i])) //find
        {
            if (current > max)
            {
                max = current;

            }
            current = 0;
        }
        else
        {
            current+=s[i]-'a' + 1;
        }
    }
    return max > current ? max : current; //最后一次计算的current需要判断
}

//solution 2
//0.使用unordered_set放置元音字母
//1.循环计算
//2.未遇到元音字母时累加，遇到元音字母后，将累加值与最大值比较，决定去留
//3.循环结束后，再比较累加值和最大值，取较大者返回(最后一次的累加值，会因循环结束而未比较)
#include <string>
#include <unordered_set>

using namespace std;

int solve(const std::string &s) 
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int max = 0, current = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (!vowels.count(s[i]))
        {
            current += s[i] - 'a' + 1;
        }
        else
        {
            if (current>max)
            {
                max=current;
            }
            current=0;
        }
    }
    return max > current ? max : current;
}



//solution 2
#include <string>
#include <unordered_set>

int solve(const std::string &s) {
  std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
  int maxVal = 0, substringVal = 0;
  
  for (const char& c : s) {
    substringVal = (!vowels.count(c)) ? substringVal + c - ('a' - 1) : 0;
    maxVal = std::max(substringVal,maxVal);
  }
  
  return maxVal;
}