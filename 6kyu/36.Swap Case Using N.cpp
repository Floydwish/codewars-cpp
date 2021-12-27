/*
36.Swap Case Using N

Instructions

Your job is to change the given string s using a non-negative integer n.

Each bit in n will specify whether or not to swap the case for each alphabetic 
character in s: if the bit is 1, swap the case; if its 0, leave it as is. 
When you finish with the last bit of n, start again with the first bit.

You should skip the checking of bits when a non-alphabetic character is encountered, 
but they should be preserved in their original positions.

Examples
swap("Hello world!", 11)  -->  "heLLO wORLd!"
...because 11 is 1011 in binary, so the 1st, 3rd, 4th, 5th, 7th, 8th and 9th alphabetical 
characters have to be swapped:

H e l l o   w o r l d !
1 0 1 1 1 x 0 1 1 1 0 x
^   ^ ^ ^    ^ ^ ^
More examples
swap("gOOd MOrniNg", 7864)        -->  "GooD MorNIng"  
swap("", 11345)                   -->  ""
swap("the lord of the rings", 0)  -->  "the lord of the rings"
*/

/*
solution 1
1.将n转为二进制string,与s对应(统一转为sizeof(int)*8位二进制)
2.循环s,若为字母,判断当对应位的二进制string为1时,转换大小写(判断转换方向)
3.s结束而n未结束时，重新开始n的循环

注：
1.对于二进制n的累加,只决定于大小写字母,其他不看
*/

#include <string>
#include <bitset>

using namespace std;

std::string swap(std::string s, int n)
{
    string strn = std::bitset<sizeof(int)*8>(n).to_string(); 
    strn = strn.erase(0,strn.find('1'));
    int countn = strn.size();
    int index = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))          //是字符
        {
            if (strn[index] == '1')  //需要转换
            {
                if (isupper(s[i]))
                {
                    s[i] = tolower(s[i]);
                }
                else if (islower(s[i]))
                {
                    s[i] = toupper(s[i]);
                }
            }
            if (++index >= countn)   //重新开始计数和匹配
                index = 0;
        }

    }

    return s;
}

