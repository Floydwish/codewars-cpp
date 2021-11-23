/*
18.Find The Parity Outlier

Instructions

You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for 
a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)

{2, -6, 8, -10, -3}

*/

//solution 1
//1.先判断查找的是奇数还是偶数
//2.查找奇数或偶数
int FindOutlier(std::vector<int> arr)
{
    //1.判断要查找的是奇数还是偶数
    bool bIsEven = false;
    int evenCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    if (evenCount >= 2)
    {
        bIsEven = true;
    }

    //1.查找特定的数
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (bIsEven && abs(arr[i] % 2) == 1)
        {
            return arr[i];
        }
        else if (!bIsEven && arr[i] % 2 == 0)
        {
            return arr[i];
        }
    }

    return 0;
}


//solution 2
//1.利用只存在单个不合群的数，可通过奇、偶数量判断最终需要哪种数为条件
//2.循环遍历，记录奇、偶个数，记录最后一个奇数、偶数
//3.最后凭借数据量，返回最后记录的特定数
int FindOutlier(std::vector<int> arr)
{
    int evenCount=0;
    int oddCount=0;
    int even=0;
    int odd=0;

    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i]%2==0 ? (evenCount++,even=arr[i]) : (oddCount++,odd=arr[i]);
    }

    return evenCount > oddCount ? odd : even;
}