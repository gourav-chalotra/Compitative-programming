#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];

        int sum = nums[0],ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                sum+=nums[i];
            else{
                ans = max(ans,sum);
                sum = nums[i];
            }
        }
        return max(ans,sum);
    }
};

int main()
{
    Solution s;
    vector<int>nums = {10,20,30,5,10,50};
    cout << s.maxAscendingSum(nums);
}