#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> ans(img.size());
        for (int i = 0; i < img.size(); i++)
        {
            for (int j = 0; j < img[i].size(); j++)
            {
                int sum = 0, size = 1;
                sum += img[i][j];
                // Right
                if (j + 1 < img[i].size())
                {
                    sum += img[i][j + 1];
                    size++;
                }
                // down
                if (i + 1 < img.size())
                {
                    sum += img[i + 1][j];
                    size++;
                }
                // left
                if (j - 1 >= 0)
                {
                    sum += img[i][j - 1];
                    size++;
                }
                // top
                if (i - 1 >= 0)
                {
                    sum += img[i - 1][j];
                    size++;
                }
                // top left;
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    sum += img[i - 1][j - 1];
                    size++;
                }
                // top Right
                if (i - 1 >= 0 && j + 1 < img[i].size())
                {
                    sum += img[i - 1][j + 1];
                    size++;
                }
                // down Right
                if (i + 1 < img.size() && j + 1 < img[i].size())
                {
                    sum += img[i + 1][j + 1];
                    size++;
                }
                // down left
                if (i + 1 < img.size() && j - 1 >= 0)
                {
                    sum += img[i + 1][j - 1];
                    size++;
                }
                cout  << "Size "<< size << endl;
                ans[i].push_back((int)(sum / size));
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    Solution s;
    vector<vector<int>> ans = s.imageSmoother(img);
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
        cout  << " "<< ans[i][j];
}