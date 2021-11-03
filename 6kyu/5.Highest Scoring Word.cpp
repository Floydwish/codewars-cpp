/*
5.Highest Scoring Word

Output
Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/


#include <string>
#include <sstream>

using namespace std;

std::string highestScoringWord(const std::string &str)
{
  //1.取出string中的word
  istringstream istr(str);
  string s;
  vector<string> vec;
  while(istr>>s)
  {
    vec.push_back(s);
  }

  //2.计算每个word的值，并取出最大值
  int highest=0;
  int index=0;
  for (int i = 0; i < vec.size(); ++i)
  {
    int cur=0;
    for (int j = 0; j < vec[i].size(); ++j)
    {
        cur+=(vec[i][j]-96);
    }
    if (cur>highest)
    {
        highest=cur;
        index=i;
    }
  }
  return vec[index];
}

