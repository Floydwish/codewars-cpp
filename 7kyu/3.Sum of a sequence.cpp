/*
3.Sum of a sequence

Instructions

Your task is to make function, which returns the sum of a sequence of integers.

The sequence is defined by 3 non-negative values: begin, end, step.

If begin value is greater than the end, function should returns 0

Examples

sequenceSum (2,2,2); // => 2
sequenceSum (2,6,2); // => 12 -> 2 + 4 + 6
sequenceSum (1,5,1); // => 15 -> 1 + 2 + 3 + 4 + 5
sequenceSum (1,5,3); // => 5 -> 1 + 4
*/

//solution 1
//直觉解法
int sequenceSum(int start, int end, int step)
{
    if (start>end)
        return 0;
    int sum=0;
    while(start<=end)
    {
        sum+=start;
        start+=step;
    }
    return sum;
}

//solution 2
//将条件判断和步进合并到for循环
int sequenceSum(int start, int end, int step)
{
    int sum=0;
    for(;start<=end;start+=step)
    {
        sum+=start;
    }
    return sum;

}

//solution 3
//使用数学公式,时间复杂度最小
//高斯算法：(首项+末项)*项数/2
int sequenceSum(int start, int end, int step)
{
    if(start>end)
        return 0;
    int n=(end-start)/step;
    int sum=(start+start+n*step)*(n+1)/2;
    return sum;

}

