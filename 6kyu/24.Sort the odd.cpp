/*24.Sort the odd

Instructions

Task
You will be given an array of numbers. You have to sort the odd numbers in ascending order 
while leaving the even numbers at their original positions.

Examples
[7, 1]  =>  [1, 7]
[5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
*/


//solution 1
//1.冒泡排序
//2.遇到偶数时跳过本次循环，继续比较

#include <vector>
#include <algorithm>

using namespace std;

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        vector<int> res(array);

        for (int i = 0; i < res.size(); ++i)
        {
            if (res[i]%2==0)
                continue;
            for (int j = i+1; j < res.size(); ++j)
            {
                if (res[j]%2==0)
                    continue;
                if (res[i] > res[j])
                {
                    swap(res[i],res[j]);
                }
            }
        }
        return res;
    }
};



//solution 2
//1.选择性拷贝奇数
//2.对奇数进行排序
//3.使用排序后的奇数对应覆盖原有奇数

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        vector<int> res(array);
        vector<int> odd;

        copy_if(res.begin(),res.end(),back_inserter(odd),[](int num){return num % 2;});
        sort(odd.begin(),odd.end());
        for (int i = 0, j=0; i < res.size(); ++i)
        {
            if (res[i] % 2)
            {
                res[i] = odd[j++];
            }
        }

        return res;
    }
};

