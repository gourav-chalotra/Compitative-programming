#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int i = 0, j = 0;
        vector<vector<int>> v(mat.size());
        while (i < mat.size())
        {
            j = 0;
            while (j < mat[i].size())
            {
                v[i].push_back(mat[i][j]);
                j++;
            }
            i++;
        }
        // rows
        i = 0;
        while (i < v.size())
        {
            // even --> left
            if (i % 2 == 0)
            {
                int t = k;
                while (t)
                {
                    j = 0;
                    int temp = v[i][0];
                    while (j < v[i].size() - 1)
                    {
                        v[i][j] = v[i][j + 1];
                        j++;
                    }
                    v[i][v[0].size() - 1] = temp;
                    t--;
                }
            }
            else // odd --> right
            {
                int t = k;
                while (t)
                {
                    j = v[i].size() - 1;
                    int temp = v[i][v[i].size() - 1];
                    while (j > 0)
                    {
                        v[i][j] = v[i][j - 1];
                        j--;
                    }
                    v[i][0] = temp;
                    t--;
                }
            }
            i++;
        }
        i = 0;
        while (i < mat.size())
        {
            j = 0;
            while (j < mat[i].size())
            {
                if (v[i][j] != mat[i][j])
                {
                    return false;
                }
                j++;
            }
            i++;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1,2}};
    cout << s.areSimilar(v, 1);
}