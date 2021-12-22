/*
33.IPv4 to int32

Instructions

Take the following IPv4 address: 128.32.10.1 This address has 4 octets where 
each octet is a single byte (or 8 bits).

1st octet 128 has the binary representation: 10000000
2nd octet 32 has the binary representation: 00100000
3rd octet 10 has the binary representation: 00001010
4th octet 1 has the binary representation: 00000001
So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the 32 bit number: 2149583361.

Write a function ip_to_int32(ip) ( JS: ipToInt32(ip) ) that takes an IPv4 address and returns a 32 bit number.

  ip_to_int32("128.32.10.1") => 2149583361

*/


//solution 1
//1.取出以'.'分割的字符串，转为10进制int
//2.转为2进制string并连接(使用std::bitset<8>转2进制字符串)
//3.转为10进制
#include <cstdint>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

uint32_t ip_to_int32(const std::string& ip) {
    
    string str = ip;
    vector<int> vec;
    int index = 0;
    int pos = 0;

    //转为4个int
    while (!str.empty())
    {
        pos = str.find('.');

        if (pos != -1)
        {
            string tmp = str.substr(0, pos);
            int n = stoi(tmp);
            vec.push_back(n);
            index = pos + 1;
            str = str.substr(pos + 1);
        }
        else
        {
            string tmp = str;
            str.clear();
            int n = stoi(tmp);
            vec.push_back(n);
        }

    }
    //连接二进制字符串
    string binary;
    for (int i = 0; i < vec.size(); i++)
    {
        int it = vec[i];
        binary += std::bitset<8>(vec[i]).to_string();
    }

    //转为十进制
    unsigned long long ret = 0;
    for (int i = binary.size()-1; i >= 0; i--)
    {
        if (binary[i]=='1')
        {
            ret += pow(2, 32 - i -1);
        }
    }
    return ret;
}


//solution 2
//1.取出以'.'分割的字符串，转为10进制int
//2.分别计算4个8bit的值,累加结果返回
#include <cstdint>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

uint32_t ip_to_int32(const std::string& ip) {
    
    string str = ip;
    int index = 0;
    int pos = 0;
    vector<int> vec;

    //转为4个int
    while (!str.empty())
    {
        pos = str.find('.');

        if (pos != -1)
        {
            string tmp = str.substr(0, pos);
            int n = stoi(tmp);
            vec.push_back(n);
            index = pos + 1;
            str = str.substr(pos + 1);
        }
        else
        {
            string tmp = str;
            str.clear();
            int n = stoi(tmp);
            vec.push_back(n);
        }

    }
    return vec[0]*pow(2,24) + vec[1]*pow(2,16) + vec[2]*pow(2,8) + vec[3];
}



//solution 3
//1.将string格式化转为4个int(使用sscanf_s格式化)
//2.分别计算4个8bit的值,累加结果返回

#include <cstdint>
#include <string>
#include <math.h>
#include <stdio.h>

uint32_t ip_to_int32_2(const std::string& ip)
{
    int a, b, c, d;
    sscanf_s(ip.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    //sscanf_s(ip.c_str(), "%i.%i.%i.%i", &a, &b, &c, &d);
    return a*pow(2,24)+b*pow(2,16)+c*pow(2,8)+d*pow(2,0);
}


