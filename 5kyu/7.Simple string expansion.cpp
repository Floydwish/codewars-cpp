/*
7.Simple string expansion

Instructions

Consider the following expansion:

solve("3(ab)") = "ababab"     -- because "ab" repeats 3 times
solve("2(a3(b))") = "abbbabbb" -- because "a3(b)" == "abbb", which repeats twice.
Given a string, return the expansion of that string.

Input will consist of only lowercase letters and numbers (1 to 9) in valid parenthesis. 
There will be no letters or numbers after the last closing parenthesis.

More examples in test cases.

Good luck!

Please also try Simple time difference


Describe(Simple_string_expansion)
{
    It(Example_tests)
    {
        Assert::That(solve("3(ab)"), Equals("ababab"));
        Assert::That(solve("2(a3(b))"),Equals("abbbabbb"));
        Assert::That(solve("3(b(2(c)))"),Equals("bccbccbcc"));
        Assert::That(solve("k(a3(b(a2(c))))"),Equals("kabaccbaccbacc"));
   
    }
}; 



*/

//solution 1
//1.循环取括号及数据
//2.当遇到有括号")"时执行一次，依次执行

#include <string>

using namespace std;

std::string solve(std::string s)
{
      
}
