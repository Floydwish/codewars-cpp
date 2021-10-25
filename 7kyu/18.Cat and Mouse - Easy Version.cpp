/*
18.Cat and Mouse - Easy Version

Instructions

You will be given a string (x) featuring a cat 'C' and a mouse 'm'. 
The rest of the string will be made up of '.'.

You need to find out if the cat can catch the mouse from it's current position. 
The cat can jump over three characters. So:

C.....m returns 'Escaped!' <-- more than three characters between

C...m returns 'Caught!' <-- as there are three characters between the two, the cat can jump.

*/

//solution 1
//循环获取位置
//判断位置的距离
//忽略顺序
//间距为4
#include <string>

std::string cat_mouse(std::string x) 
{
    int posC=0;
    int posM=0;
    for (int i = 0; i < x.size(); ++i)
    {
        if (x[i]=='C')
        {
            posC=i;
        }
        else if (x[i]=='m')
        {
            posM=i;
        }
        
    }
    if (abs(posM-posC)<=4)
    {
        return "Caught!";
    }
    else
        return "Escaped!";
}


//solution 2
//利用目标字符串特点
//即，C和m总是第1个或最后1个，得出临界的总长为5
//以此为判断依据
#include <string>

std::string cat_mouse(std::string x) 
{
    return x.size()>5? "Escaped!" : "Caught!";
}

//solution 3
//利用目标字符串特点
//即，C和m总是第1个或最后1个,'.'为连续，是否能找到"...."可以判断能否抓到
//以此为判断依据
//使用string的find接口
#include <string>

std::string cat_mouse(std::string x) 
{
    return x.find("....") != std::string::npos ? "Escaped!" : "Caught!";
}

//solution 4
//利用目标字符串特点
//即，C和m总是第1个或最后1个,'.'为连续，是否能找到"...."可以判断能否抓到
//以此为判断依据
//使用string的count接口
#include <string>
#include <algorithm>

std::string cat_mouse(std::string x) 
{
    return count(x.begin(),x.end(),'.') > 3 ? "Escaped!" : "Caught!";
}