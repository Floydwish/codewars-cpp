/*
26.Sums of Parts

Instructions

Let us consider this example (array written in general format):

ls = [0, 1, 3, 6, 10]

Its following parts:

ls = [0, 1, 3, 6, 10]
ls = [1, 3, 6, 10]
ls = [3, 6, 10]
ls = [6, 10]
ls = [10]
ls = []
The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]

The function parts_sums (or its variants in other languages) will take as parameter a list ls and 
return a list of the sums of its parts as defined above.

Other Examples:
ls = [1, 2, 3, 4, 5, 6] 
parts_sums(ls) -> [21, 20, 18, 15, 11, 6, 0]

ls = [744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358]
parts_sums(ls) -> [10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414, 9291270, 2581057, 2580168, 2579358, 0]
Notes
Take a look at performance: some lists have thousands of elements.
Please ask before translating.

*/

//solution 1
//0.循环，从前往后
//1.使用标准库accumulate函数
//2.计算总值，并作为结果vector的第一个元素
//3.循环，每次顺序减去一个值，并作为vector的后续元素
//注：循环调用accumulate的方式效率不够，会超时
#include <vector>
#include <numeric>

using namespace std;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  vector<unsigned long long> ret;
  unsigned long long total = accumulate(ls.begin(), ls.end(),0);
  ret.push_back(total);
  for (int i = 0; i < ls.size(); ++i)
  {
      total -= ls[i];
      ret.push_back(total);
  }
  return ret;
}

ls = [1, 2, 3, 4, 5, 6] 
parts_sums(ls) -> [21, 20, 18, 15, 11, 6, 0]

 Assert::That(partsSum({0, 1, 3, 6, 10}), Equals(V{20, 20, 19, 16, 10, 0}));

 [ 59, 10, 10, 9, 6, 0 ]


//solution 2
//1.循环，从后往前
//2.第1个为空的，通过初始化处理
//3.后续每往前一次，进行一次累加
//4.累加结果，使用下标运算符赋值给vector
#include <vector>

using namespace std;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  size_t n = ls.size();
  vector<unsigned long long> ret(n+1,0);
  size_t sum=0;
  while(n--)
  {
    sum += ls[n];
    ret[n] = sum;
  }
  return ret;
}


//solution 3
//1.使用标准库接口partial_sum
//2.遍历范围是从后往前
//3.累加值，同样从后往前放置到目标vector中，并且最后一个是初始化的0
#include <vector>
#include <numeric>

using namespace std;

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  size_t n = ls.size();
  vector<unsigned long long> ret(n+1,0);
  partial_sum(ls.crbegin(),ls.crend(),ret.rbegin()+1);
  return ret;
}