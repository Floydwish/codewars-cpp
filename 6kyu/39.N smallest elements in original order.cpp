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