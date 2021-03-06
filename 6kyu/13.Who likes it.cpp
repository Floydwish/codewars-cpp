/*
13.Who likes it?

Instructions

You probably know the "like" system from Facebook and other pages. People can "like" blog posts, 
pictures or other items. We want to create the text that should be displayed next to such an item.

Implement the function which takes an array containing the names of people that like an item. 
It must return the display text as shown in the examples:

[]                                -->  "no one likes this"
["Peter"]                         -->  "Peter likes this"
["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
Note: For 4 or more names, the number in "and 2 others" simply increases.
*/

//solution 1
//直接方法
#include <string>

using namespace std;

std::string likes(const std::vector<std::string> &names)
{
    string ret;
    int nameSize = names.size();
    switch(nameSize)
    {
        case 0:
        {
            ret="no one likes this";
            break;
        }
        case 1:
        {
            ret=names[0]+" likes this";
            break;
        }
        case 2:
        {
            ret=names[0]+" and ";
            ret+=names[1];
            ret+=" like this";
            break;
        }
        case 3:
        {
            ret=names[0]+", ";
            ret+=names[1];
            ret+=" and ";
            ret+=names[2];
            ret+=" like this";
            break;
        }
        default:
        {
            ret=names[0]+", ";
            ret+=names[1];
            ret+=" and ";
            ret+= to_string(nameSize-2);
            ret+=" others like this";
            break;
        }
    }


    return ret; 
}


//solution 2
//0.简化
//1.可以直接返回
//2.可以一次连接多个字符串
#include <string>

using namespace std;

std::string likes(const std::vector<std::string> &names)
{
    int nameSize = names.size();
    switch(nameSize)
    {
        case 0: return "no one likes this";
        case 1: return names[0]+" likes this";
        case 2: return names[0]+" and " + names[1] +" like this";
        case 3: return names[0]+", " + names[1] + " and " + names[2] + " like this";
        default:return names[0]+", " + names[1] + " and " + to_string(nameSize-2) + " others like this";
    }
}