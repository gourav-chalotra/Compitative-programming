#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int i = 1, j = 1;
        int sumK = 1;
        vector<int> ans;
        while (i < nums.size() && j < nums.size())
        {

            sumK += nums[j] - nums[j - 1];
            cout << "sumK:  " << sumK << endl;
            cout << "nums[j] - nums[j - 1] : " << (nums[j] - nums[j - 1]) << endl;
            if (j >= k - 1)
            {
                if (sumK == k && (j - i == k - 1))
                {
                    cout << "i: " << i << " j: " << j << endl;
                }
                sumK -= nums[i] - nums[i - 1];
                i++;
            }
            j++;

            // bool check = false;
            // int max = INT_MIN;
            // cout << "i: "<< i << endl;
            // for (int j = i; j < (k+i-1); j++)
            // {
            //     cout << "j: "<< j << endl;
            //     cout << "nums[j]: "<< nums[j] << " nums[j-1]: "<< nums[j-1] << endl;
            //     if (nums[j-1] < nums[j])
            //     {
            //         check = true;
            //         max = nums[j + 1];
            //     }
            //     else
            //     {
            //         check = false;
            //         max = -1;
            //         break;
            //     }
            // }
            // cout << "\n \n \n"<< endl;
            // ans.push_back(max);
            // i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    vector<int> ans = s.resultsArray(nums, 3);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}