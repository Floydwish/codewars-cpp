/*
5.Highest Scoring Word

Output
Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/


//solution 1
//1.使用输入输出控制类istringstream提取string中的word
//2.使用Ascii码得出每个word值(a为97)
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

//solution 2
//0.solution 1优化提取word的方式，提取计算单个word值的方法
//1.使用输入输出控制类istringstream提取string中的word
//2.使用Ascii码得出每个word值(a为97)
#include <string>
#include <sstream>

using namespace std;
int getWordValue(string word);

std::string highestScoringWord(const std::string &str)
{
  istringstream is(str);
  string word;
  string highestWord;
  int highest=0;
  int cur=0;

  while(is >> word)             // 取出word
  {
    cur=getWordValue(word);     // 计算word的值
     if (cur > highest)
     {
         highest=cur;
         highestWord=word;
     }
  }
  return highestWord;
}

int getWordValue(string word)
{
    int nRes=0;
    for (int i = 0; i < word.size(); ++i)
    {
        nRes+=(word[i]-96);
    }
    return nRes;
}



//solution 3
//0.使用getline提取word
//1.独立的计算word值的方法
//2.使用Ascii码得出每个word值(a为97)
#include <string>
#include <sstream>

using namespace std;
int getWordValue(string word);

std::string highestScoringWord(const std::string &str)
{
  istringstream is(str);
  string word;
  string highestWord;
  int highest=0;
  int cur=0;

  while(getline(is,word,' '))   // 取出word
  {
    cur=getWordValue(word);     // 计算word的值
     if (cur > highest)
     {
         highest=cur;
         highestWord=word;
     }
  }
  return highestWord;
}

int getWordValue(string word)
{
    int nRes=0;
    for (int i = 0; i < word.size(); ++i)
    {
        nRes+=(word[i]-96);
    }
    return nRes;
}


