/*
2.RGB To Hex Conversion

Instructions

The rgb function is incomplete. Complete it so that passing in RGB decimal values 
will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. 
Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
*/

//solution 1
//1.判断并处理在0~255范围外的数据
//2.使用stringstream格式化输出rgb值，主要包括std::hex, std::setfill('0')填充0,std::setw(2)设置宽度为2
//3.使用算法transform将十六进制转为大写

//注：在transform中使用std::toupper失败，原因：
//Just use ::toupper instead of std::toupper. That is, toupper defined in the global namespace, 
//instead of the one defined in std namespace.
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        stringstream str;
        if (r < 0)   r = 0;
        if (g < 0)   g = 0;
        if (b < 0)   b = 0;
        if (r > 255)   r = 255;
        if (g > 255)   g = 255;
        if (b > 255)   b = 255;

        string s;
        str << std::hex << std::setfill('0') <<std::setw(2) << r;
        str << std::hex << std::setfill('0') << std::setw(2) << g;
        str << std::hex << std::setfill('0') << std::setw(2) << b;
        str >> s;
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
};



//solution 2
//1.使用stringstream格式化输出rgb值，主要包括std::hex, std::setfill('0')填充0,std::setw(2)设置宽度为2
//2.使用2个三目运算返回每一个rgb的适当值
//3.分别设置宽度为2，再连接起来作为结果
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        std::stringstream str;

        str << std::hex << std::setfill('0') << std::uppercase
            << std::setw(2) << (r < 0 ? 0 : (r > 255 ? 255 : r))
            << std::setw(2) << (g < 0 ? 0 : (g > 255 ? 255 : g))
            << std::setw(2) << (b < 0 ? 0 : (b > 255 ? 255 : b));

        return str.str();
    }
};



