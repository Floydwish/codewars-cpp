/*
35.Alphabetized

Instructions

The alphabetized kata
Re-order the characters of a string, so that they are concatenated into 
a new string in "case-insensitively-alphabetical-order-of-appearance" order. 
Whitespace and punctuation shall simply be removed!

The input is restricted to contain no numerals and only words containing the english alphabet letters.

Example:

alphabetized("The Holy Bible") # "BbeehHilloTy"  

*/

/*
solution 1
1.移除空白字符
2.移除标点符号
3.stable排序,忽略大小写比较

注：
1.remove_if 将Pred(如::isspace)为Ture的移除,返回新的end,但并未改变string的大小(即，从begin到新end是符合要求的,从新end到旧end并未清除)
2.string的erase用于移除新end到旧end之间的元素，到此才是完全移除，并得到新的string
3.使用sort排序时,vs2019上得出的结果是符合测试的,但提交到codewars通不过，于是改用stable_sort稳定排序
*/
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool insensitiveCompare(char a,char b)
{
    return toupper(a) < toupper(b);
}

std::string alphabetized(const std::string& str)
{
    string res(str);
    res.erase(remove_if(res.begin(), res.end(), ::isspace), res.end());
    res.erase(remove_if(res.begin(), res.end(), ::ispunct), res.end());
    stable_sort(res.begin(), res.end(), insensitiveCompare);
    
    return res;
}


#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

/*
solution 2
//1.solution 1优化
//2.使用isalpha排除掉不合要求的字符,作为参数传给remove_if进行处理
//3.将判断排序的方法作为第3个参数传给stable_sort进行排序
*/

std::string alphabetized(const std::string& str)
{
    string res(str);
    res.erase(remove_if(res.begin(), res.end(), [](char c) {return !isalpha(c); }), res.end());
    stable_sort(res.begin(), res.end(), [](char a, char b) {return toupper(a) < toupper(b); });
    return res;
}