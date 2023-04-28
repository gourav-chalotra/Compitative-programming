#include<iostream>
#include<vector>
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int>ans(nums.size(),0);
        std::vector<int>miss;
        int i = 0;
        for(i; i < nums.size(); i++)
            ans[nums[i]-1] = 1;
        i = 0;
        for(i; i < ans.size();i++)
        {
            if(ans[i]==0)
            {
                miss.push_back(i+1);
            }
        }
        return miss;
    }
};