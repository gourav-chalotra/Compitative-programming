// Problem : https://leetcode.com/problems/equal-sum-grid-partition-i/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        using ull =  unsigned long long;
        ull totalSum = 0;
        for(int i = 0; i < grid.size(); i++)
            {
                for(int j = 0; j < grid[i].size(); j++)
                    {
                        totalSum += grid[i][j];
                    }
            }
        // horizontal Cutts
        ull sectionCut = 0;
        for(int i = 0; i < grid.size()-1; i++)
            {
                for(int j = 0; j < grid[i].size(); j++)
                    {
                        sectionCut = sectionCut + grid[i][j];
                    }
                cout << "secton Cut(H): "<< sectionCut << endl;
                if(totalSum-sectionCut == sectionCut){
                    return true;
                }
            }
        // vertical cutts
        sectionCut = 0;
        for(int j = 0; j < grid[0].size()-1; j++)
            {
                for(int i = 0; i < grid.size(); i++)
                    {
                        sectionCut = sectionCut + grid[i][j];
                    }
                cout << "secton Cut(V): "<< sectionCut << endl;
                if(totalSum-sectionCut == sectionCut){
                    return true;
                }
            }
        return false;
    }
};
int main()
{
    
}