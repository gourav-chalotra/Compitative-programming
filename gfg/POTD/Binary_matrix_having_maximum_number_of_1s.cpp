#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N)
    {
        // code here
        vector<int> v;
        int row;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << mat[j][i] << " ";
                if (mat[j][i])
                {
                    row = j;
                    v.push_back(row);
                    v.push_back(N - i);
                    return v;
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>>v1 = {{0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1}};
    vector<int> ans = s.findMaxRow(v1,4);
    cout << "Row: "<< ans.at(0)<<endl;
    cout << "Total number of 1s: "<< ans.at(1)<<endl;
}