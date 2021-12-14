/*
1.Moving Zeros To The End

Instructions

Write an algorithm that takes an array and moves all of the zeros to the end, 
preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*/


//solution 1
//1.循环遍历迭代器,删除为0的元素,记录0元素的个数 
//2.最后在结果vector后面添加0指定数量的0元素

#include <vector>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {

  vector<int> ret(input);
  int size = ret.size();
  int zeroCnt=0;
  for (vector<int>::iterator it= ret.begin(); it != ret.end();)
  {
      if (*it == 0)
      {
          zeroCnt++;
          it = ret.erase(it); //erase返回下一个元素的迭代器，作为更新值
      }
      else
        it++;
  }

  for (int i = 0; i < zeroCnt; ++i)
  {
      ret.push_back(0);
  }
  return ret;
}


auto move_zeroes(std::vector<int> v) {
  stable_partition(begin(v), end(v), std::negate());
  return v;
}


//solution 2 (移动非0元素)
//1.创建一个同样与input同样大小的vector,并初始化所有元素为0
//2.循环遍历input，将不为0的元素拷贝到结果vector
//3.返回结果vector,其中不为0的元素按顺序排列，为0的元素在初始化就处理好了

#include <vector>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {
    vector<int> vec(input.size(),0);

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] != 0)
        {
            vec.push_back(input[i]);
        }
    }
    return vec;

}


//solution 3
//1.使用stable_partition(固定顺序分组,根据第三个参数返回值将vector分成固定顺序的2部分)
//2.使用lambda function
//资料：https://en.cppreference.com/w/cpp/language/lambda

#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input) {

    vector<int> vec(input);
    stable_partition(vec.begin(), vec.end(), [](int x) {return x; });
    return vec;
}



//solution 4
//1.使用stable_partition(固定顺序分组,根据第三个参数返回值将vector分成固定顺序的2部分)
//2.使用negate(),返回带有相反符号的相同值，作为判断依据(负数视为true,0视为false,以此排序)

#include <vector>
#include <algorithm>

using namespace std;
std::vector<int> move_zeroes(const std::vector<int>& input) {
  vector<int> vec(input);
  stable_partition(vec.begin(), vec.end(), std::negate());
  return vec;
}