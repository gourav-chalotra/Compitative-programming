#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> flipped(matrix[0].size());
        cout << flipped.size() << endl;
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                flipped[j].push_back(matrix[i][j]);
            }
        }
        return flipped;
    }
};
int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}};
    Solution s;
    s.transpose(v);
}