/*
23.Split Strings

Instructions

Complete the solution so that it splits the string into pairs of two characters. 
If the string contains an odd number of characters then it should replace the missing 
second character of the final pair with an underscore ('_').

Examples:

solution("abc") // should return {"ab", "c_"}
solution("abcdef") // should return {"ab", "cd", "ef"}


*/

//solution 1
//1.循环取子字符串，加入到结果vector
//2.若最后单独剩下一个，则将最后一个字符连接'_'作为子字符串，加入结果

#include <string>
#include <vector>

using namespace std;

std::vector<std::string> solution(const std::string &s)
{
    vector<string> ret;
   
    for (int i = 0; i < s.size(); i+=2)
    {
         string str;
        if (i+1 == s.size())
        {
            str = s[i] + '_';
            ret.push_back(str);
            break;
        }
        str = s.substr(i,2);
        ret.push_back(str);
    }
    return ret; // Your code here
}


//solution 2
//solutino 1优化版
//1.循环取子字符串，加入到结果vector
//2.若最后单独剩下一个，则将最后一个字符连接'_'作为子字符串，加入结果

#include <string>
#include <vector>

using namespace std;

std::vector<std::string> solution(const std::string &s)
{
    vector<string> ret;
   
    for (int i = 0; i < s.size(); i+=2)
    {
        string str;
        str = s.substr(i,2);
        ret.push_back(str);
    }
    if(s.size()%2)
        ret[ret.size()-1] += '_';
    return ret; // Your code here
}

