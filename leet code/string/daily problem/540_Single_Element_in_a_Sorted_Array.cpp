// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &num)
    {
        for (int i = 1; i < num.size(); i += 2)
        {
            if (num[i] != num[i - 1])
            {
                cout << num[i - 1] << endl;
                return num[i - 1];
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 1, 2, 2, 3,  8, 8};
    cout << s.singleNonDuplicate(v);
    return 0;
}