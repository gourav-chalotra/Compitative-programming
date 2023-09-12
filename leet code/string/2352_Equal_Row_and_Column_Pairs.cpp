#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int countEqPair = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            // Row
            vector<int> r(grid[i].begin(), grid[i].end());
            
            for(int j = 0; j < grid.size(); j++)
            {
                // coloum
                vector<int> c;
                int check = 0;
                for(int k = 0; k < grid.size(); k++)
                {
                    if(grid[k][j] != grid[i][k])
                    {
                        check = 1;
                        break;
                    }
                }
                if(!check)
                {
                    countEqPair++;
                }
            }
        }
        return countEqPair;
    }
};

int main()
{
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution s;
    cout << s.equalPairs(grid);
    return 0;
}