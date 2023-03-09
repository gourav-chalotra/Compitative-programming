#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max < nums[i])
            {
                max = nums[i];
            }
        }
        if (max == val)
        {
            for (auto a : nums)
            {
                if (a == val)
                {
                    break;
                }
                ans++;
            }
            return ans;
        }
        else
        {
            for (int i = 0; i < nums.size(); i += nums[i] != val)
            {
                if (nums[i] == val)
                {
                    for (int j = i; j < nums.size() - 1; j++)
                    {
                        nums[j] = nums[j + 1];
                    }
                    ans++;
                }
            }
        }
        cout << ans << endl;
        return nums.size() - ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2, 2, 3, 3};
    cout << s.removeElement(nums, 3) << endl;
    return 0;
}