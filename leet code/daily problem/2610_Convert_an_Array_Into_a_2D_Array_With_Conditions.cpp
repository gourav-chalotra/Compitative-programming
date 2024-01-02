#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findMatrix(vector<int> &nums)
    {
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

        int row = maxElement, i = 1, j = 0;
        vector<vector<int>> ans(row);
        while (j < row)
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
        cout << "printing of 2d vector" << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution s;
    vector<int> a = {1, 3, 4, 1, 2, 3, 1};
    s.findMatrix(a);
}