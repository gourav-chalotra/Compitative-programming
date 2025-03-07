#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if(grid.size() == 1 && grid[0].size() == 1)
        {
            if(grid[0][0] == 1)
                return -1;
            else if(grid[0][0] == 0)
                return 0;
        }
        int mint = 0, noOfFreshOrg = 0, countFreshOrg = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                {
                    noOfFreshOrg++;
                }
            }
        if(noOfFreshOrg == 0)
            return 0;
        queue<pair<int, int>> v;
        while (!q.empty())
        {
            int indexI = q.front().first, indexJ = q.front().second;
            q.pop();
            if (indexI - 1 >= 0)
            {
                if (grid[indexI - 1][indexJ] == 1)
                {
                    v.push({indexI - 1, indexJ});
                    grid[indexI - 1][indexJ] = 2;
                    countFreshOrg++;
                }
            }
            if (indexJ - 1 >= 0)
            {
                if (grid[indexI][indexJ - 1] == 1)
                {
                    v.push({indexI, indexJ - 1});
                    grid[indexI][indexJ - 1] = 2;
                    countFreshOrg++;
                }
            }
            if (indexJ + 1 < grid[0].size())
            {
                if (grid[indexI][indexJ + 1] == 1)
                {
                    v.push({indexI, indexJ + 1});
                    grid[indexI][indexJ + 1] = 2;
                    countFreshOrg++;
                }
            }
            if (indexI + 1 < grid.size())
            {
                if (grid[indexI + 1][indexJ] == 1)
                {
                    v.push({indexI+1, indexJ});
                    grid[indexI + 1][indexJ] = 2;
                    countFreshOrg++;
                }
            }
            if (q.empty())
            {
                mint++;
                cout << mint << endl;
                q = v;
                while (!v.empty())
                {
                    v.pop();
                }
            }
        }
        return (countFreshOrg == noOfFreshOrg) ? (mint - 1) : -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;
    cout << "\n"
         << s.orangesRotting(grid);
}