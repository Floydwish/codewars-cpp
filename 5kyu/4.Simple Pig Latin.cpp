/*
4.Simple Pig Latin

Instructions

Move the first letter of each word to the end of it, then add "ay" to the end of the word. 
Leave punctuation marks untouched.

Examples
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay  
pigIt('Hello world !');     // elloHay orldway !
*/




//solution 1
//1.使用stringstream将string分割成单词
//2.单词的截取和连接处理,标点符号处理
#include <string>
#include <sstream>

using namespace std;

std::string pig_it(std::string str)
{
    stringstream ss(str);
    string word;
    string ret;
    while (ss >> word)
    {
        if (isalpha(word[0]))
        {
            ret += word.substr(1) + word[0] + "ay ";
        }
        else
            ret += word + " ";
    }
    return ret.substr(0,ret.length()-1);
}


//solution 2