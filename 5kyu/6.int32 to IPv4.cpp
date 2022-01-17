/*
6.int32 to IPv4

Instructions

Take the following IPv4 address: 128.32.10.1

This address has 4 octets where each octet is a single byte (or 8 bits).

1st octet 128 has the binary representation: 10000000
2nd octet 32 has the binary representation: 00100000
3rd octet 10 has the binary representation: 00001010
4th octet 1 has the binary representation: 00000001
So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 2149583361

Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.

Examples
2149583361 ==> "128.32.10.1"
32         ==> "0.0.0.32"
0          ==> "0.0.0.0"

*/


//solution 1
//1.使用bitset将整数ip转为32位二进制
//2.循环，每8位转为十进制
//3.连接结果字符串
#include <string>
#include <bitset>

using namespace std;

int bitToInt(string str)
{
    int ret=0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        ret = ret * 2 + stoi(str.substr(i,1));
    }
    return ret;
}

std::string uint32_to_ip(uint32_t ip)
{
    string str = std::bitset<32>(ip).to_string();

    string ret;

    for (size_t i = 0; i < str.size(); i+=8)
    {
        string tmp = str.substr(i, 8);
        int n = bitToInt(tmp);
        ret += to_string(n);
        ret += '.';
    }
    return ret.substr(0,ret.size()-1);
}



//solution 2
//1.使用ostringstream进行格式化
//2.每次取8位并屏蔽其他位
//3.连接字符串

//注：格式化输出的工具库中应加上ostringstream类
#include <sstream>

std::string uint32_to_ip(uint32_t ip)
{
    std::ostringstream ostr;
    ostr << (ip >> 24) << "."
        << (ip >> 16 & 0xff) << "."
        << (ip >> 8 & 0xff) << "."
        << (ip & 0xff);
    return ostr.str();
}


//solution 3
//1.每次取8位并屏蔽其他位
//2.使用to_string将int转为string
//3.连接结果string
std::string uint32_to_ip(uint32_t ip)
{
    std::string ret =
        std::to_string(ip >> 24) + "."
        + std::to_string(ip >> 16 & 0xff) + "."
        + std::to_string(ip >> 8 & 0xff) + "."
        + std::to_string(ip & 0xff);
    return ret;
}
