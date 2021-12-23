/*
34.Count the smiley faces!

Instructions

Given an array (arr) as an argument complete the function countSmileys that 
should return the total number of smiling faces.

Rules for a smiling face:

Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
Every smiling face must have a smiling mouth that should be marked with either ) or D
No additional characters are allowed except for those mentioned.

Valid smiley face examples: :) :D ;-D :~)
Invalid smiley faces: ;( :> :} :]

Example
countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;
Note
In case of an empty array return 0. You will not be tested with invalid input 
(input will always be an array). Order of the face (eyes, nose, mouth) elements 
will always be the same.

*/

/*
solution 1
1.列出smile字符串
2.循环查找,若能找到则累加
3.返回累加结果
*/

#include <string>

using namespace std;

int countSmileys(std::vector<std::string> arr)
{
    string res = ":) :-) :~) ;) ;-) ;~) :D :-D :~D ;D ;-D ;~D";
    int count=0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (string::npos != res.find(arr[i]))
        {
            count++;
        }
    }
  return count;
}


/*
solution 2
1.构造正则表达式字符串
2.使用正则方法regex_match进行循环匹配,并计数

":) :-) :~) ;) ;-) ;~) :D :-D :~D ;D ;-D ;~D";
*/
#include <string>
#include <regex>

using namespace std;

int countSmileys(std::vector<std::string> arr)
{
    int count = 0;
    std::regex smiles_regex("[:|;][-|~]?[)|D]");

    for (int i = 0; i < arr.size(); ++i)
    {
        if (std::regex_match(arr[i],smiles_regex))
        {
            count++;
        }
    }
    return count;
}




#include <regex>

int countSmileys(std::vector<std::string> arr)
{
  int count = 0;
  std::regex smiles_regex("[:|;](-|~)?[)|D]");
  
  for (auto &smile : arr) {
    if (std::regex_match(smile, smiles_regex))
      count++;
  }

  return count;
}