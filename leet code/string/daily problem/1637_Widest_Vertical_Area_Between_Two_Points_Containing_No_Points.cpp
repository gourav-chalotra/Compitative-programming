// 1637. Widest Vertical Area Between Two Points Containing No Points
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int i = 0;
        vector<int>x;
        for(int i = 0; i < points.size(); i++)
            x.push_back(points[i][0]);
        
        sort(x.begin(),x.end());

        i = points.size()-1;
        int ans = 0;
        while(i >= 1)
        {
            ans = max(ans,x[i] - x[i-1]);
            i--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>>points = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    cout << s.maxWidthOfVerticalArea(points);
}