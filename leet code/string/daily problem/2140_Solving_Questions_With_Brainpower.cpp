#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long c(int i,vector<vector<int>>& q,vector<long long>&dp){
        if(i>=q.size())return 0;
        long long ans=0;
        if(dp[i]!=-1)return dp[i];
        ans = max(q[i][0]+c(i+q[i][1]+1,q,dp),c(i+1,q,dp));
        dp[i]=ans;
        return ans;
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
      vector<long long>dp(n,-1);
      return c(0,q,dp);  
    }
};
int main()
{
    Solution s;
    // 79
    std::vector<std::vector<int>> arr = {{12, 46}, {78, 19}, {63, 15}, {79, 62}, {13, 10}};
    std::cout << s.mostPoints(arr);
}