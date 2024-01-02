#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Find maximum element
        sort(nums.begin(), nums.end());
        int maxElement = nums[nums.size() - 1] + 1;
        vector<int> arr(maxElement, 0);
        maxElement = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
            maxElement = max(maxElement, arr[nums[i]]);
        }
        int  i = 1, j = 0;
        vector<vector<int>> ans(maxElement);
        while (j < maxElement)
        {
            i = 1;
            while (i < arr.size())
            {
                if (arr[i])
                {
                    arr[i]--;
                    ans[j].push_back(i);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> a = {1, 3, 4, 1, 2, 3, 1};
    s.findMatrix(a);
}