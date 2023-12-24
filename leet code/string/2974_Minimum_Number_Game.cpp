// Question link: https://leetcode.com/problems/minimum-number-game/description/
// Solution link: https://leetcode.com/problems/minimum-number-game/solutions/4453898/beats-1-0-0/
// 2974. Minimum Number Game

#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i = 0;i < nums.size()-1;i+=2)
        {
            ans.push_back(nums[i+1]);
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
int main()
{
    
}