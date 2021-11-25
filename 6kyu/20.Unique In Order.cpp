/*
20.Unique In Order

Instructions

Implement the function unique_in_order which takes as argument a sequence and
 returns a list of items without any elements with the same value next to each other and 
 preserving the original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}

*/


// solution 1
// 1.从下标1开始循环遍历
// 2.比较当前元素和前一个元素是否相等，相等则删除，不等则前进
// 3.返回符合要求的vector
#include <string>
#include <vector>

using namespace std;

std::vector<char> uniqueInOrder(const std::string& iterable)
{
    string ret(iterable.begin(),iterable.end());
    int index = 1;
    while (index < ret.size())
    {
        if (ret[index] == ret[index - 1])
        {
            ret.erase(index, 1);
        }
        else
            index++;
    }
    vector<char> r(ret.begin(), ret.end());
    return r;
}


template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
    string ret(iterable.begin(), iterable.end());
    int index = 1;
    while (index < ret.size())
    {
        if (ret[index] == ret[index - 1])
        {
            ret.erase(index, 1);
        }
        else
            index++;
    }
    vector<T> r(ret.begin(), ret.end());
    return r;
}



// solution 2
// solution 1优化
// 1.循环遍历
// 2.当结果vector中为空，或者 结果vector中最后一个元素不等于当前元素时，当前元素符合要求，放置到结果vector中
// 3.返回结果vector
#include <string>
#include <vector>

using namespace std;

std::vector<char> uniqueInOrder(const std::string& iterable)
{
    vector<char> result;
    for (int i = 0; i < iterable.size(); ++i)
    {
        if (result.empty() || result.back() != iterable[i])
        {
            result.push_back(iterable[i]);
        }
    }
    return result;
}


template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
    vector<T> result;
    for (int i = 0; i < iterable.size(); ++i)
    {
        if (result.empty() || result.back() != iterable[i])
        {
            result.push_back(iterable[i]);
        }
    }
    return result;
}


// solution 3
// 1.使用标准库algorithm接口unique_copy
// 2.将非重复的元素拷贝到结果vector(通过迭代器插入结果vector)
// 3.返回结果vector
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

std::vector<char> uniqueInOrder(const std::string& iterable)
{
    vector<char> result;
    unique_copy(iterable.begin(), iterable.end(), back_inserter(result));
    return result;
}


template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable) {
    vector<T> result;
    unique_copy(iterable.begin(), iterable.end(), back_inserter(result));
    return result;
}