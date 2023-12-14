#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& mat, int r, int c)
    {
        int oneInRow = 0,oneInColoum = 0;
        // Coloum
        for(int i = 0; i < mat[0].size(); i++)
        {
            // cout << "mat[r][i] "<< mat[r][i] << endl;
            if(mat[r][i])
                oneInColoum++;
        }
        // cout << "oneInColoum " << oneInColoum << endl; 
        // Row
        for(int i = 0; i < mat.size(); i++)
        {
            // cout << "mat[i][c] "<< mat[i][c] << endl;
            if(mat[i][c])
                oneInRow++;
        }
        // cout << "oneInRow " << oneInRow << endl; 
        if(oneInRow == 1 && oneInColoum == 1)
        return true;
        return false;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int r = 0, c = 0,ans = 0;
        for(;r < mat.size(); r++)
        {
            for(c = 0; c < mat[r].size(); c++)
                if(mat[r][c] == 1){
                    cout << "r "<< r << " c " <<c << endl;
                    if(check(mat,r,c))
                        ans++; 
                }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> mat = {{0,0},{0,0},{1,0}};
    Solution s;
    s.numSpecial(mat);
}