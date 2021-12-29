/*
37.Sum of Two Integers

Instructions

Task
Given Two integers a , b , find The sum of them ,
 BUT You are not allowed to use the operators + and -

Notes
The numbers (a,b) may be positive , negative values or zeros .

Returning value will be an integer .

Input >> Output Examples
1- Add (5,19) ==> return (24) 

2- Add (-27,18) ==> return (-9)

3- Add (-14,-16) ==> return (-30)


1. 0101 | 0001 0011 = 0001 0111 

*/

/*

Add(5,19)
a = 0000 0101 & 0001 0011 = 0000 0001 = 1
b = 0000 0101 ^ 0001 0011 = 0001 0110 = 22
x = a << 1 = 2
y = b = 22 

a = x & y = 0000 0010 & 0001 0110 = 0000 0010 = 2
b = x ^ y = 0000 0010 ^ 0001 0110 = 0001 0100 = 20
x = a << 1 = 4
y = b = 20 

a = x & y = 0000 0100 & 0001 0100 = 4
b = x ^ y = 0000 0100 ^ 0001 0100 = 16
x = a <<1 = 8
y = b = 16

a = x & y = 0000 1000 & 0001 0000 = 0
b = x ^ y = 0000 1000 ^ 0001 0000 = 24
x = a << 1 = 0
y = b =24

Add(3,3)
a = 0011 & 0011 = 0011 = 3
b = 0011 ^ 0011 = 0
x = a << 1 = 0110 = 6
y = b = 0

a = x & y = 0110 & 0000 = 0000
b = x ^ y = 0110 ^ 0000 = 0110
x = a << 1 =0
y = b = 6

*/


//solution 1
//1.使用位运算
//2.循环判断进位是否为0,计算非进位值与进位值
//3.进位值每次循环左移一位,再进行运算
//4.直到进位值为0
int ADD(int x, int y)
{
    int a,b;
    do{
        a = x & y;  //进位
        b = x ^ y;  //非进位
        x = a << 1; //进位的值
        y = b;      //非进位的值
    }while(a);       //直到进位为0
    return b;
}

//solution 1
//1.使用位运算
//2.循环判断进位是否为0,计算非进位值与进位值
//3.进位值每次循环左移一位,再进行运算
//4.直到进位值为0
int Add(int x, int y)
{
    int a,b;
    while(y!=0)
    {
        a = x & y;  // 进位
        b = x ^ y;  // 非进位
        x = b;      // 非进位值
        y = a << 1; // 进位值
    }
    return b;
}


//solution 2
//1.使用位运算
//2.将非进位作为下一层递归调用的参数x,将进位左移1位作为下一层递归的参数y
//3.判断进位是否为0,作为递归的结束条件
int Add(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return Add(x^y + (x & y<<1));
}

#include <vector>   
#include <numeric>  //accumulate


//solution 3
//1.使用accumulate接口累加
int Add(int x, int y)
{
    std::vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    return accumulate(vec.begin(),vec.end(),0);
}


//solution 4
/*
template <class T> struct plus;
Addition function object class
Binary function object class whose call returns the result of adding its two arguments (as returned by operator +).

Generically, function objects are instances of a class with member function operator() defined.
This member function allows the object to be used with the same syntax as a function call.

It is defined with the same behavior as:

template <class T> struct plus : binary_function <T,T,T> {
  T operator() (const T& x, const T& y) const {return x+y;}
};

*/
//1.声明类的实例Add
//2.实例Add()与函数Add()调用方式一致

#include <functional>   //template <class T> struct plus;

std::plus<int> Add; 





