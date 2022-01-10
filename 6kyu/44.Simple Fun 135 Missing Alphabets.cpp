/*
44.Simple Fun #135: Missing Alphabets

Instructions

Task
Given string s, which contains only letters from a to z in lowercase.

A set of alphabet is given by abcdefghijklmnopqrstuvwxyz.

2 sets of alphabets mean 2 or more alphabets.

Your task is to find the missing letter(s). You may need to output them by the order a-z. 
It is possible that there is more than one missing letter from more than one set of alphabet.

If the string contains all of the letters in the alphabet, return an empty string ""

Example
For s='abcdefghijklmnopqrstuvwxy'

The result should be 'z'

For s='aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy'

The result should be 'zz'

For s='abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxy'

The result should be 'ayzz'

For s='codewars'

The result should be 'bfghijklmnpqtuvxyz'

Input/Output
[input] string s
Given string(s) contains one or more set of alphabets in lowercase.

[output] a string
Find the letters contained in each alphabet but not in the string(s). Output them by the order a-z. If missing alphabet is repeated, please repeat them like "bbccdd", not "bcdbcd"
*/


//solution 1
//1.计算当前string中重复次数最多的字母
//2.遍历字母表找出并累加缺失的字母
#include <string>
#include <algorithm>

using namespace std;

std::string missing_alphabets(const std::string& s) {
    string str("abcdefghijklmnopqrstuvwxyz");
    int cur = 0;
    int max = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        cur = count(s.begin(), s.end(), s[i]);
        if (cur > max)
        {
            max = cur;
        }
    }
    string ret;
    for (int i = 0; i < str.size();i++)
    {
        cur = count(s.begin(), s.end(), str[i]);

        if(max-cur != 0)
            ret += string(max - cur, str[i]);
    }
    return ret;
}