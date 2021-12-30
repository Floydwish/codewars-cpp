/*
38.Basic Encryption

Instructions

The most basic encryption method is to map a char to another char by a certain math rule. 
Because every char has an ASCII value, we can manipulate this value with a simple math expression. 
For example 'a' + 1 would give us 'b', because 'a' value is 97 and 'b' value is 98.

You will need to write a method which does exactly that -
s
get a string as text and an int as the rule of manipulation, and should return encrypted text. for example:

encrypt("a",1) = "b"

Full ascii table is used on our question (256 chars) - so 0-255 are the valid values.

If the value exceeds 255, it should 'wrap'. ie. if the value is 345 it should wrap to 89.

Good luck.
*/


//solution 1
//1.循环遍历待加密string
//2.判断每个字符是否超出0-255范围
//3.若未超出范围则+rule,否则+rule-256
#include <string>
std::string encrypt(std::string text, int rule) {
  for (int i = 0; i < text.size(); ++i)
  {
       if (text[i] + rule > 255)
       {
           text[i]=text[i] + rule - (255+1);
       }
       else 
       {
           text[i]=text[i] + rule;
       }   

  }
  return text;
};

//solution 2 - solution 1 优化
//1.使用%256同时处理超出或未超出255的部分
#include <string>
std::string encrypt(std::string text, int rule) {
  std::string ret(text);
  for (int i = 0; i < text.size(); ++i)
  {
    ret[i]=(text[i] + rule)%256;
  }
  return ret;
};



//solution 3
//1.循环遍历待加密string
//2.每个字符+rule,再转为char(截取出未超过256的部分)

#include <string>
using namespace std;
std::string encrypt(std::string text, int rule) {
    string ret(text);
    for (int i = 0; i < text.size(); ++i)
    {
       ret[i] = (char)text[i] + rule;
    }
    return ret;
};

#include <string>
#include <algorithm>

using namespace std;

//solution 4
//1.使用标准库接口for_each,处理每一个text中的值
//2.构造自定义策略[定值](入参){处理每一个字符},超出部分按%256处理
std::string encrypt(std::string text, int rule) 
{
    for_each(text.begin(),text.end(),[rule](char &a){a=(a+rule)%256;});
    return text;
}