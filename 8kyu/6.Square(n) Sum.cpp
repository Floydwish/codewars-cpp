//6.Square(n) Sum

//Instructions
//Complete the square sum function so that it squares each number passed into it and then sums the results together.

//For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

//solution 1
#include <vector>

int square_sum(const std::vector<int>& numbers)
{
	int sum=0;
	for(int i=0;i<numbers.size();i++)
		sum+=numbers[i]*numbers[i];
    return sum;
}