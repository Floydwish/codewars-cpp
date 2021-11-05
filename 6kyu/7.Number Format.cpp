/*
7.Number Format

Instructions

Format any integer provided into a string with "," (commas) in the correct places.

Example:

numberFormat(100000); // return '100,000'
numberFormat(5678545); // return '5,678,545'
numberFormat(-420902); // return '-420,902'

*/

//solution 1
//1.复制插入法
//2.从字符串低位开始遍历
//3.遇到符合条件的插入数字和逗号，否则仅插入数字
//4.注意负数的处理

#include<string>

using namespace std;

std::string numberFormat(long long n){
    string strn=to_string(n);
    string res;

    int size = strn.size();

    int index=0;
    if(n < 0)
        index=1;

    for (; index < size; ++index)
    {
        if ( n<0 && index ==1 )
        {
            res.push_back('-');
        }
        if ((size-index)%3==1 && (size-index)/3 != 0)
        {
            res.push_back(strn[index]);
            res.push_back(',');
        }
        else
        {
            res.push_back(strn[index]);
        }
    }
    return res;
}

numberFormat(100000); // return '100,000'
numberFormat(5678545); // return '5,678,545'
numberFormat(-420902); // return '-420,902'


//solution 2
//1.字符串插入法
//2.从后往前遍历，遍历间隔为3
//3.仅当前一个字符为'-'时，退出遍历

#include<string>

using namespace std;

std::string numberFormat(long long n){
    string strn=to_string(n);

    for (int i = strn.size()-3; i > 0; i-=3)
    {
        if (strn.at(i-1)=='-')
            break;
        strn.insert(strn.begin()+i,',');
     }
    return strn;
}

std::string numberFormat(long long n) {
  std::string str = std::to_string(n);
  for (int i = str.size() - 3; i > 0; i-=3)
  {
    if (str.at(i-1) == '-') break;
    str.insert(str.begin() + i, ',');
  }
  return str;
}

