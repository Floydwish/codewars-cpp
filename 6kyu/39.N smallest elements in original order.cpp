/*
39.N smallest elements in original order

Instructions

Your task is to write a function that does just what the title suggests 
(so, fair warning, be aware that you are not getting out of it just throwing
 a lame bas sorting method there) with an array/list/vector of integers and 
 the expected number n of smallest elements to return.

Also:

the number of elements to be returned cannot be higher than the array/list/vector length;
elements can be duplicated;
in case of duplicates, just return them according to the original order (see third example for more clarity).
Same examples and more in the test cases:

firstNSmallest({1,2,3,4,5},3) == {1,2,3}
firstNSmallest({5,4,3,2,1},3) == {3,2,1}
firstNSmallest({1,2,3,4,1},3) == {1,2,1}
firstNSmallest({1,2,3,-4,0},3) == {1,-4,0}
firstNSmallest({1,2,3,4,5},0) == {}
*/


//solution 1
//1.排序数组
//2.取得目标子数组(排序后的)
//3.遍历原数组,通过在目标子数组中查找比对,同时满足原排序+在目标数组中的要求
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> firstNSmallest(const std::vector<int> arr, int n) {
    vector<int> vec(arr);
    vector<int> ret;
    //1.特殊情况处理
    if (n <=  0 || arr.size() < n)
    {
        return {};
    }

    //2.排序
    sort(vec.begin(), vec.end());
 
    //3.获取目标值(非原排序)
    vector<int> tar(vec.begin(), vec.begin()+n);
    vector<int>::iterator it;

    //4.遍历原数组,并与目标数组对比,获取原序元素
    for (int i = 0; i < arr.size(); ++i)
    {
        it = find(tar.begin(), tar.end(), arr[i]);
        if ( it!= tar.end())
        {
            ret.push_back(arr[i]);
            tar.erase(it);
        }

        if (ret.size() == n)
            break;
    }
    return ret;

}


//solution 2
//1.循环遍历vector,循环次数为待删除元素的数量
//2.每次循环找出一对最小值和最大值,删除其中的最大值(最大值从后向前查找和删除)

/*
minmax_element()的返回值说明：(如果有相等的最小值,返回第1个,如果有相等的最大值,返回最后一个)
Return value
a pair consisting of an iterator to the smallest element as the first element and 
an iterator to the greatest element as the second. Returns std::make_pair(first, first) 
if the range is empty. If several elements are equivalent to the smallest element, 
the iterator to the first such element is returned. If several elements are equivalent 
to the largest element, the iterator to the last such element is returned.
*/
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> firstNSmallest(const std::vector<int> arr, int n) 
{
    vector<int> ret(arr);
    for (int i = 0; i < arr.size() - n; i++)
    {
        auto at = minmax_element(ret.begin(), ret.end());
        ret.erase(at.second);
    }
    return ret;
}


//solution 3
//1.循环遍历vector,循环次数为待删除元素的数量
//2.每次循环,从后往前找出并删除最大值
/*
说明：
0.由于题目测试要求,若存在相等的值,一个需要删除,一个不需要删除,那么应该删除原排序中靠后的
1.使用max_element反向查找最大值(传入reverse_iterator,由ret.rbegin()和ret.rend()提供)
2.找出最大值后返回为reverse_iterator,不能直接用于erase中,需转换为iterator
3.使用reverse_iterator的base()获取iterator,该iterator指向的元素为reverse_iterator指向的后1个元素
4.因此,需要在erase中传入iterator指向元素的前一个元素(或者,将reverse_iterator+1-前移1个元素，再获取iterator)
*/
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> firstNSmallest(const std::vector<int> arr, int n)
{
    vector<int> ret(arr);
    vector<int>::reverse_iterator it;
    for (int i = 0; i < arr.size() - n; i++)
    {
        it = max_element(ret.rbegin(), ret.rend());

        //printf("it = %d, it+1 = %d\n", *it, *(it + 1));
        //printf("it.base() = %d, (it+1).base() = %d\n", *(it.base()), *((it + 1).base()));
        
        ret.erase(it.base()-1);     //操作iterator
        //ret.erase((it+1).base()); //操作reverse_iterator(效果一致)
      
   
    }
    return ret;
}


