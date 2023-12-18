#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        map<int, int> mp;
        int twiceNum = -1, notFindNum = -1;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                mp[grid[i][j]]++;
                if (mp[grid[i][j]] == 2)
                    twiceNum = grid[i][j];
            }
        for (int i = 1; i <= grid.size() * grid.size(); i++)
        {
            if (mp[i] == 0)
            {
                notFindNum = i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(twiceNum);
        ans.push_back(notFindNum);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = s.findMissingAndRepeatedValues(grid);
    for (auto i : ans)
    {
        cout << i;
    }
}