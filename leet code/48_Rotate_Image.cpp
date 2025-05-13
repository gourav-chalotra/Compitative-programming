#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = matrix.size() - 1, k = 0; j >= 0 && k < matrix.size(); j--, k++)
            {
                ans[i][k] = matrix[j][i];
            }
            cout << endl;
        }
        matrix = ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    s.rotate(image);
}