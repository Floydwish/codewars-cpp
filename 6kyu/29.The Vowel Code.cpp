/*
29.The Vowel Code

Step 1: Create a function called encode() to replace all the lowercase vowels 
in a given string with numbers according to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about 
uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels 
according to the same pattern shown above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function 
will correspond to vowels.

*/

//solution 1
//1.条件判断
#include <string>

using namespace std;

std::string encode(const std::string &str) {
  string ret;
  for (int i = 0; i < str.size(); ++i)
  {
     if (str[i]=='a')
     {
         ret.push_back('1');
     }
     else if (str[i]=='e')
     {
         ret.push_back('2');
     }
     else if (str[i]=='i')
     {
         ret.push_back('3');
     }
     else if (str[i]=='o')
     {
         ret.push_back('4');
     }
     else if (str[i]=='u')
     {
         ret.push_back('5');
     }
     else
     {
        ret.push_back(str[i]);
     }       
  }
  return ret;
}

std::string decode(const std::string &str) {
  string ret;
  for (int i = 0; i < str.size(); ++i)
  {
     if (str[i]=='1')
     {
         ret.push_back('a');
     }
     else if (str[i]=='2')
     {
         ret.push_back('e');
     }
     else if (str[i]=='3')
     {
         ret.push_back('i');
     }
     else if (str[i]=='4')
     {
         ret.push_back('o');
     }
     else if (str[i]=='5')
     {
         ret.push_back('u');
     }
     else
     {
        ret.push_back(str[i]);
     }       
  }
  return ret;
}

//solution 2
//1.将键值对添加到map
//2.查找、修改
#include <string>
#include <unordered_map>

using namespace std;

static map<char,char> m{{'a','1'},{'e','2'},{'i','3'},{'o','4'},{'u','5'}};
static map<char,char> m1{{'1','a'},{'2','e'},{'3','i'},{'4','o'},{'5','u'}};

std::string encode(const std::string &str) {
  string ret(str);
  for (int i = 0; i < ret.size(); ++i)
  {
      if (m.count(ret[i]) == 1)
      {
          ret[i]=m[ret[i]];
      }
  }
  return ret;
}

std::string decode(const std::string &str) {
  string ret(str);
  for (int i = 0; i < ret.size(); ++i)
  {
      if (m1.count(ret[i]) == 1)
      {
          ret[i]=m1[ret[i]];
      }
  }
  return ret;
}


//solution 3
//encode
//1.将键值对添加到map
//2.查找、修改

//decode
//1."12345"对应"aeiou"
//2.遍历string,将字符大小在'1'~'5'范围的提取出来，替换为对应的'aeiou'
#include <string>
#include <unordered_map>

using namespace std;

static map<char,char> m{{'a','1'},{'e','2'},{'i','3'},{'o','4'},{'u','5'}};

std::string encode(const std::string &str) {
  string ret(str);
  for (int i = 0; i < ret.size(); ++i)
  {
      if (m.count(ret[i]) == 1)
      {
          ret[i]=m[ret[i]];
      }
  }
  return ret;
}

std::string decode(const std::string &str) {
  string ret(str);
  string s('aeiou');
  for (int i = 0; i < ret.size(); ++i)
  {
      if ('0'< ret[i] && ret[i] < '6')
      {
          ret[i]=s[ret[i]-'1'];
      }
  }
  return ret;
}



