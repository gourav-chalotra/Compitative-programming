// 3643. Flip Square Submatrix Vertically

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        vector<int> temp;
        for (int col = y; col < y + k && col < grid[x].size(); col++)
        {
            for (int row = x; row < x + k && row < grid.size(); row++)
            {
                temp.push_back(grid[row][col]);
            }
            reverse(temp.begin(), temp.end());

            for (int i = 0, row = x; i < temp.size() && row < x+k; i++,row++)
                grid[row][col] = temp[i];
    
        }
        return grid;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int x = 1, y = 0, k = 3;
    s.reverseSubmatrix(grid, x, y, k);
}
