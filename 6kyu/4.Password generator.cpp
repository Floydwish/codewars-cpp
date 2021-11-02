/*4.Password generator

Instructions

You need to write a password generator that meets the following criteria:

6 - 20 characters long
contains at least one lowercase letter
contains at least one uppercase letter
contains at least one number
contains only alphanumeric characters (no special characters)
Return the random password as a string.

Note: "randomness" is checked by counting the characters used in the generated passwords - 
all characters should have less than 50% occurance. Based on extensive tests, the normal rate is around 35%.

*/

#include <string>

using namespace std;

std::string password_gen() 
{
    string res;
    //1.随机长度
    int len=rand()%(20-6+1)+6;
    string anum("01234567890123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    
    //2.前len-3个随机0~61
    for (int i=0;i<len;++i)
    {
        if (i<len/3)
        {
            int indexNum=rand()%(10-1+1)+1;
            res.push_back(anum[indexNum-1]);
        }
        else if (i>=len/3 && i<len/3*2)
        {
            int indexUpcase=rand()%(36-11+1)+11;
            res.push_back(anum[indexUpcase-1]);
        }
        else
        {
            int indexLowcase=rand()%(62-37+1)+37;
            res.push_back(anum[indexLowcase-1]);
        }
    }

    return res;
}