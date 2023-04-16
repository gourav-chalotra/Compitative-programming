#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int index = 0, maxOnes = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int rowOnes = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                    rowOnes++;
            }
            if (maxOnes < rowOnes)
            {
                index = i;
                maxOnes = rowOnes;
            }
        }
        vector<int> ans;
        ans.push_back(index);
        ans.push_back(maxOnes);
        return ans;
    }
};

int main()
{
    vector<vector<int>> mat = {{0,0},{1,1},{0,0}};
    Solution s;
    vector<int> ans = s.rowAndMaximumOnes(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}