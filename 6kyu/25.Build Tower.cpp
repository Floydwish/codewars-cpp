/*
25.Build Tower

Instructions

Build Tower
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Python: return a list;
JavaScript: returns an Array;
C#: returns a string[];
PHP: returns an array;
C++: returns a vector<string>;
Haskell: returns a [String];
Ruby: returns an Array;
Lua: returns a Table;
Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ', 
  ' *** ', 
  '*****'
]
and a tower of 6 floors looks like below

[
  '     *     ', 
  '    ***    ', 
  '   *****   ', 
  '  *******  ', 
  ' ********* ', 
  '***********'
]

*/

//solution 1
//1.找出层数与*的规律，*个数 = 层数*2-1
//2.找出层数与空格的规律，左空格数 = 右空格数 = 最高层数 - 当前层数
//3.使用string构造函数,制造出指定数量的*和空格数，连接左空格、*号、右空格，作为结果

#include <vector>
#include <string>

using namespace std;


class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        vector<string> res;

        for (int i = 1; i <= nFloors; ++i)
        {
          string space((nFloors-i),' ');
          string str(i*2-1,'*');
          res.push_back(space+str+space);
        }
        return res;
    }
};


//solution 2
//优化solutin 1, 直接连接string,节省了空间
//1.找出层数与*的规律，*个数 = 层数*2-1
//2.找出层数与空格的规律，左空格数 = 右空格数 = 最高层数 - 当前层数
//3.使用string构造函数,制造出指定数量的*和空格数，连接左空格、*号、右空格，作为结果

#include <vector>
#include <string>

using namespace std;


class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        vector<string> res;

        for (int i = 1; i <= nFloors; ++i)
        {
          res.push_back(string(nFloors-i,' ')+
                        string(i*2-1,'*')+
                        string(nFloors-i,' '));
        }
        return res;
    }
};