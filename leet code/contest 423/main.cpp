#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        for (int i = 0; i <= nums.size() - k; i++)
        {

            bool check1 = false;
            for (int j = i; j < i + k - 1 && (i + k - 1) < nums.size(); j++)
            {

                if (nums[j] >= nums[j + 1])
                {

                    check1 = true;
                    break;
                }
                check1 = true;
            }

            bool check2 = false;
            for (int j = i + k; j < (i + (k * 2) - 2) && j < nums.size(); j++)
            {
                // cout << nums[j] << endl;
                if (nums[j] >= nums[j + 1])
                {
                    cout << nums[j] << " " << nums[j + 1] << endl;
                    check2 = false;
                    break;
                }
                check2 = true;
            }
            cout << "\n\n\n\n"
                 << endl;
            if (check2 && check1)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    cout << s.hasIncreasingSubarrays(nums, 5);
}