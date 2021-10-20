/*
14.Find the vowels

Instructions

We want to know the index of the vowels in a given word, for example, 
there are two vowels in the word super (the second and fourth letters).

So given a string "super", we should return a list of [2, 4].

Some examples:
Mmmm  => []
Super => [2,4]
Apple => [1,5]
YoMama -> [1,2,4,6]
NOTES
Vowels in this context refers to: a e i o u y (including upper case)
This is indexed from [1..n] (not zero indexed!)

*/


//solution 1
//直接比较
#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
    std::vector<int> res;
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'Y')
        {
            res.push_back(i+1);
        }
    }
    return res;
}

//solution 2
//循环查找
//使用string的find接口
#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
    std::vector<int> res;
    std::string allVowel("aeiouyAEIOUY");
    for (int i = 0; i < word.size(); ++i)
    {
        if (std::string::npos!=allVowel.find(word[i]))
        {
            res.push_back(i+1);
        }
    }
    return res;
}


