#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {

        vector<vector<int>> guardsAndWalls(m, vector<int>(n, 1));

        // walls

        for (int i = 0; i < walls.size(); i++)
        {
            for (int j = 0; j < walls[i].size(); j++)
            {
                guardsAndWalls[walls[i][0]][walls[i][1]] = 0;
            }
        }

        // Walls '0'
 
        // Guards
        for (int i = 0; i < guards.size(); i++)
        {
            for (int j = 0; j < guards[i].size(); j++)
            {
                guardsAndWalls[guards[i][0]][guards[i][1]] = -1;
            }
        }


        for (int i = 0; i < guardsAndWalls.size(); i++)
        {
            for (int j = 0; j < guardsAndWalls[i].size(); j++)
            {
                if (guardsAndWalls[i][j] == -1)
                {
                    int colRight = j + 1;
                    while (colRight < guardsAndWalls[i].size())
                    {
                        if (guardsAndWalls[i][colRight] == 1 || guardsAndWalls[i][colRight] == -2)
                        {
                            guardsAndWalls[i][colRight] = -2;
                            colRight++;
                        }
                        else
                            break;
                    }
                    int colLeft = j - 1;
                    while (colLeft >= 0)
                    {
                        if (guardsAndWalls[i][colLeft] == 1 || guardsAndWalls[i][colLeft] == -2)
                        {
                            guardsAndWalls[i][colLeft] = -2;
                            colLeft--;
                        }
                        else
                            break;
                    }

                    int rowTop = i - 1;
                    while (rowTop >= 0)
                    {
                        if (guardsAndWalls[rowTop][j] == 1 || guardsAndWalls[rowTop][j] == -2)
                        {
                            guardsAndWalls[rowTop][j] = -2;
                            rowTop--;
                        }
                        else
                            break;
                    }
                    int rowDown = i + 1;
                    while (rowDown < guardsAndWalls.size())
                    {
                        if ((guardsAndWalls[rowDown][j] == 1 || guardsAndWalls[rowDown][j] == -2))
                        {
                            guardsAndWalls[rowDown][j] = -2;
                            rowDown++;
                        }
                        else
                            break;
                    }
                }
            }
        }

        int sum = 0;
        for (auto i : guardsAndWalls)
        {
            for (auto j : i)
            {
                if (j == 1)
                    sum += j;
            }
        }
        return sum;
    }
};

int main()
{

    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> wall = {{0, 1}, {2, 2}, {1, 4}};

    Solution s;
    cout << s.countUnguarded(m, n, guards, wall);
}