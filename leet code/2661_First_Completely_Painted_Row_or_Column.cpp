#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<vector<int>> &mat, int r, int c)
    {
        int rowCuntZ = 0, columnCountZ = 0;
        // row
        for (int i = 0; i < mat[r].size(); i++)
            rowCuntZ+=mat[r][i];

        if (!rowCuntZ)
            return true;
        // columns
        for (int i = 0; i < mat.size(); i++)
            columnCountZ+=mat[i][c]; 
        if (!columnCountZ)
            return true;
        return false;
    }
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int,pair<int,int>>match;
        pair<int,int> points;
        int i;
        for(i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[i].size(); j++)
            {
                points = {i,j};
                match[mat[i][j]] = points;
            }

        for(i = 0; i < arr.size(); i++)
        {
            mat[match[arr[i]].first][match[arr[i]].second] = 0;
            if(check(mat,match[arr[i]].first,match[arr[i]].second))
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << s.firstCompleteIndex(arr, mat);
    return 0;
}