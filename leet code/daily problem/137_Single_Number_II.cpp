#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        if (nums.size() < 4)
            return 0;

        if (nums.size() % 3 == 0)
            return 0;

        sort(nums.begin(), nums.end());
        // last index value to secound last value check
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
        {
            return nums[nums.size() - 1];
        }
        else if (nums[0] != nums[1])
        { // first index value to secound index value check
            return nums[0];
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
        return 0;
    }
};
int main()
{
}