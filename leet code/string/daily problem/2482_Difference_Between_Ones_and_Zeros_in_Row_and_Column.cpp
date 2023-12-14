#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {

        vector<int> rows;
        vector<int> coloum;
        vector<vector<int>>diff(grid.size());
        // coloum sum
        for (int i = 0; i < grid.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                sum += grid[i][j];
            }
            coloum.push_back(sum);
        }
        // row sum
        for (int i = 0; i < grid[0].size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < grid.size(); j++)
            {
                sum += grid[j][i];
            }
            // cout << "Sum "<< sum << endl;
            rows.push_back(sum);
        }

        // for (auto i : rows)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : coloum)
        //     cout << i << " ";
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                cout << (coloum[i]+rows[j] - (int)(rows.size()-rows[j]) - (int)(coloum.size()-coloum[i])) << endl;
                diff[i].push_back(coloum[i]+rows[j] - (int)(rows.size()-rows[j]) - (int)(coloum.size()-coloum[i]));
            }
            cout << endl;
        }
        return diff;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
    s.onesMinusZeros(grid);
}