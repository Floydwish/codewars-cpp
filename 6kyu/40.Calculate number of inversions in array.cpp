/*
40.Calculate number of inversions in array(倒序)

Instructions

Array inversion indicates how far the array is from being sorted.

Inversions are pairs of elements in array that are out of order.

Examples
[1, 2, 3, 4]  =>  0 inversions
[1, 3, 2, 4]  =>  1 inversion: 2 and 3
[4, 1, 2, 3]  =>  3 inversions: 4 and 1, 4 and 2, 4 and 3
[4, 3, 2, 1]  =>  6 inversions: 4 and 3, 4 and 2, 4 and 1, 3 and 2, 3 and 1, 2 and 1
Goal
The goal is to come up with a function that can calculate inversions for any arbitrary array111

*/


//solution 1
#include <vector>
#include <algorithm>

using namespace std;

class Kata {
public:
    int countInversions(const std::vector<int>& vec) {
        int count = 0;
        int b = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            b = vec[i];
            count += count_if(vec.begin() + i, vec.end(), [b](int a) {return a < b; });
        }
        return count;
    }
};