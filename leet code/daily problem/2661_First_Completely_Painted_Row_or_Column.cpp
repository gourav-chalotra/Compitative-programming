#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int, pair<int, int>> Count;
        vector<int> row(mat[0].size(), 0);
        vector<int> col(mat.size(), 0);

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                Count[mat[i][j]] = pair<int, int>(i, j);
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {

            row[Count[arr[i]].second]++;
            col[Count[arr[i]].first]++;

            if (row[Count[arr[i]].second] == mat.size() || col[Count[arr[i]].first] == mat[0].size())
                return i;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mart = {{3,2,5}, {1,4,6}, {8,7,9}};
    cout << s.firstCompleteIndex(arr, mart);
}