/*
1.Remove the parentheses

Instructions

Remove the parentheses
In this kata you are given a string for example:

"example(unwanted thing)example"
Your task is to remove everything inside the parentheses as well as the parentheses themselves.

The example above would return:

"exampleexample"

Notes
Other than parentheses only letters and spaces can occur in the string. 
Don't worry about other brackets like "[]" and "{}" as these will never appear.
There can be multiple parentheses.
The parentheses can be nested.

*/

//solution 1
//1.查找出哪些是作为结果，作为结果字串
//2.反过来就要找出括号内的，判断哪些是括号内的
//3.关键是判断括号的深度，深度为0时就可以作为结果

#include <string>

using namespace std;

std::string remove_parentheses(const std::string &str)
{
    string result;
    int begin=0;
    int parentheses_count=0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i]=='(')
        {
            parentheses_count+=1;
        }
        else if (str[i]==')')
        {
            parentheses_count-=1;
        }
        else
        {
            if (parentheses_count==0)
            {
                result.push_back(str[i]);
            }
        }
    }
   
    return result;
}
    