#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        // digonal down
        for(int i = 0;i < grid.size(); i++)
        {
            vector<int>ans;
            int tempI = i,tempJ = 0;
            while(tempI < grid.size() && tempJ < grid.size())
            {
                cout << tempI << " " << tempJ << endl; 
                ans.push_back(grid[tempI++][tempJ++]);
            }
            for(auto i : ans)
                cout << i << " ";
            cout << "\n\n\n"<< endl;
            sort(ans.begin(),ans.end());
            reverse(ans.begin(),ans.end());
            tempI = i,tempJ = 0;
            int temp = 0;
            while(tempI < grid.size() && tempJ < grid.size() && temp < ans.size())
            {
                grid[tempI++][tempJ++] = ans[temp++];
            }
        }
        // dignal top (increassing order order)
        for(int j = 1; j < grid.size(); j++)
        {
            vector<int>ans;
            int tempJ = j,tempI = 0;
            while(tempJ < grid.size() && tempI < grid.size())
            {
                ans.push_back(grid[tempI++][tempJ++]);
            }
            sort(ans.begin(),ans.end());
            int temp = 0;
            tempJ = j,tempI = 0;
            while(tempJ < grid.size() && tempI < grid.size() && temp < ans.size())
            {
                grid[tempI++][tempJ++] = ans[temp++];
            }
        }

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        return grid;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    s.sortMatrix(grid);
}