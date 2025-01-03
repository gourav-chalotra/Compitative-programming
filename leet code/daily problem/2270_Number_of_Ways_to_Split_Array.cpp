#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0, noValid = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        long long rightSum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            rightSum += nums[i];
            if (rightSum >= sum - rightSum)
            {
                noValid++;
            }
        }
        return noValid;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10, 4, -8, 7};
    cout << s.waysToSplitArray(nums) << endl;
    return 0;
}