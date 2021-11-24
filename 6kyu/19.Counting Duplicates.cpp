/*
19.Counting Duplicates

Instructions

Count the number of Duplicates
Write a function that will return the count of distinct case-insensitive alphabetic characters and 
numeric digits that occur more than once in the input string. The input string can be assumed to 
contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice

*/

#include <unordered_map>
#include <algorithm>
using namespace std;


size_t duplicateCount(const std::string& in); // helper for tests
{
    size_t count = 0;
    string str(in);
    unordered_map<char,int> map;
    unordered_map<char, int>::iterator iter;
    for (size_t i = 0; i < str.size(); ++i)
    {
        map[toupper(str[i])]++;
    }
    for (iter = map.begin(); iter != map.end(); ++iter)
    {
        if(map[iter->first] > 1)
            count++;
    }
    return count;
}

//solution 1
//1.循环遍历，将元素放置到map中
//2.循环遍历，将map中值大于1的元素累加
//3.返回累加结果
size_t duplicateCount(const char* in)
{
    size_t count = 0;
    string str(in);
    unordered_map<char,int> map;
    unordered_map<char, int>::iterator iter;
    for (size_t i = 0; i < str.size(); ++i)
    {
        map[toupper(str[i])]++;
    }
    for (iter = map.begin(); iter != map.end(); ++iter)
    {
        if(map[iter->first] > 1)
            count++;
    }
    return count;
}


//solution 2
//1.循环遍历，将元素放置到map中
//2.使用Algorithm中的count_if,遍历map
//3.增加isNeedCount接口判断每一个map中的pair的值是否大于1，若大于1则返回true，否则返回false
//4.将isNeedCount作为count_if的第3个参数
//5.返回count_if的结果
bool isNeedCount(std::pair<char,int> pair)
{
    int r = pair.second;
    if (pair.second > 1)
        return true;
    return false;
}

size_t duplicateCount2(const char* in)
{
    size_t count = 0;
    unordered_map<char, int> map;
    for (const char* c = in; *c != '\0'; c++)
    {
        map[toupper(*c)]++;
    }
    return count_if(map.begin(), map.end(), isNeedCount);
}


//solution 3
//1.循环遍历，将元素放置到map中
//2.使用Algorithm中的count_if,遍历map
//3.将solution 2 中的isNeedCount接口内置到count_if调用中
//4.格式为：[](传入参数){返回true or false;}, 整体作为count_if的第3个参数
//5.返回count_if的结果
size_t duplicateCount(const char* in)
{
    size_t count = 0;
    unordered_map<char, int> map;
    for (const char* c = in; *c != '\0'; c++)
    {
        map[toupper(*c)]++;
    }
    return count_if(map.begin(), map.end(), [](pair<char, int> pa) 
        {return pa.second > 1; }
    );
}