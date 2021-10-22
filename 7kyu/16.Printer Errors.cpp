/*
16.Printer Errors

Instructions

In a factory a printer prints labels for boxes. For one kind of boxes the printer has to use colors which, 
for the sake of simplicity, are named with letters from a to m.

The colors used by the printer are recorded in a control string. For example a "good" control string would 
be aaabbbbhaijjjm meaning that the printer used three times color a, four times color b, one time color h 
then one time color a...

Sometimes there are problems: lack of colors, technical malfunction and a "bad" control string is produced e.g. 
aaaxbbbbyyhwawiwjjjwwm with letters not from a to m.

You have to write a function printer_error which given a string will return the error rate of the printer as a 
string representing a rational whose numerator is the number of errors and the denominator the length of the 
control string. Don't reduce this fraction to a simpler expression.

The string has a length greater or equal to one and contains only letters from a to z.

Examples:
s="aaabbbbhaijjjm"
printer_error(s) => "0/14"

s="aaaxbbbbyyhwawiwjjjwwm"
printer_error(s) => "8/22"

*/


//solution 1
//循环查找
#include <string>

using namespace std

class Printer
{
public:
    static std::string printerError(const std::string &s);
};

std::string Printer::printerError(const std::string &s)
{
    std::string str("abcdefghijklm");
    int count=0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (std::string::npos==str.find(s[i]))
        {
            count++;
        }
    }
    return std::to_string(count)+"/"+std::to_string(s.size()); 
}


//solution 2
//循环比较
#include <string>

using namespace std

class Printer
{
public:
    static std::string printerError(const std::string &s);
};

std::string Printer::printerError(const std::string &s)
{
    int count=0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i]<'a' || s[i]>'m')
        {
            count++;
        }
    }
    return std::to_string(count)+"/"+std::to_string(s.size());
}


//solution  411023199003221531
class Printer
{
  public:
    static std::string printerError(std::string const & s)
    {
      auto const denum = s.length();
      auto const numer = std::count_if(
          s.cbegin(), s.cend(),
          [](char c) { return c > 'm'; });
      
      return std::to_string(numer) + "/" + std::to_string(denum);
    }
};