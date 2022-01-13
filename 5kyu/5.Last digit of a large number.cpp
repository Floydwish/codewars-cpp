/*
5.Last digit of a large number

Instructions

Define a function that takes in two non-negative integers a and b and 
returns the last decimal digit of a^b . Note that a and b may be very large!

For example, the last decimal digit of 9^7 is 9, since 9^7= 47829699 . 
The last decimal digit of (2^200)2^300, which has over 10^92 decimal digits, 
is 6. Also, please take 0^0 to be 1.

You may assume that the input will always be valid.

Remarks
JavaScript, C++, R, PureScript
Since these languages don't have native arbitrarily large integers, 
your arguments are going to be strings representing non-negative integers instead.



规律：
The last digit of powers of 1 is always                 1
The last digits of powers of 2 repeat in a cycle of     2 4 8 6 
The last digits of powers of 3 repeat in a cycle of     3 9 7 1
The last digits of powers of 4 repeat in a cycle of     4 6
The last digit of powers of 5 is always                 5
The last digit of powers of 6 is always                 6
The last digits of powers of 7 repeat in a cycle of     7 9 3 1
The last digits of powers of 8 repeat in a cycle of     8 4 2 6
The last digits of powers of 9 repeat in a cycle of     9 1

Describe(Sample_Tests) {
  It(Tests) {
    Assert::That(last_digit("4", "1"), Equals(4));
    Assert::That(last_digit("4", "2"), Equals(6));
    Assert::That(last_digit("9", "7"), Equals(9));
    Assert::That(last_digit("10", "10000000000"), Equals(0));
    Assert::That(last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"), Equals(6));
    Assert::That(last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"), Equals(7));
  }


 -> 6^76 -> 6
 -> 3^51 -> 3^3=27->7
};

*/


//solution 1
//未通过
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int> > mp =
{
    {0,{0}},
    {1,{1}},
    {2,{6,2,4,8}},
    {3,{1,3,9,7}},
    {4,{6,4}},
    {5,{5}},
    {6,{6}},
    {7,{1,7,9,3}},
    {8,{6,8,4,2}},
    {9,{1,9}}
};


int last_digit(const std::string& str1, const std::string& str2) 
{
    //取最后一位
    int len = 0;
    int base = 0;
    if (str1.length() >= 1)
    {
        string strbase = str1.substr(str1.length() - 1, 1);
        base = atoi(strbase.c_str());
        len = mp[base].size();
    }
    int exponent = 0;
    int index = 0;
    if (str2.length() == 1)
    {
        string str = str2.substr(str2.length() - 1, 1);
        exponent = atoi(str.c_str());
        index = exponent % len;
    }
    else if (str2.length() >= 2)
    {
        string str = str2.substr(str2.length() - 2, 2);
        exponent = atoi(str.c_str());
        index = exponent % len;
    }

    return mp[base][index];
}


//solution 2
//未通过
#include <string>
#include <math.h>

using namespace std;

int modul(int a, string str2)
{
    int mod = 0;
    for (int i = 0; i < str2.length(); i++)
    {
        mod = (mod * 10 + str2[i] - '0') % a;
    }
    return mod;
}

int last_digit(const std::string& str1, const std::string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    //如果底数是0
    if (len1 == 1 && str1[0]=='0')
    {
        return 0;
    }
    //如果指数是0
    if (len2 == 1 && str2[0] == '0')
    {
        return 1;
    }
    //如果底数和指数都是0
    if (len1 == 1 && str1[0] == '0' && len2 == 1 && str2[0] == '0')
    {
        return 1;
    }

    //计算指数能否被4整除,返回余数
    int exponent = (modul(4, str2) == 0) ? 4 : modul(4, str2);

    int res = pow(str1[len1-1] - '0', exponent);

    return res % 10;
}




