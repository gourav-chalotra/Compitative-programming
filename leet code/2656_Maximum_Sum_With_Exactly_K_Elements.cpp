#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    int maximizeSum(std::vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        while(k)
        {
            sum+=nums[nums.size()-1];
            nums[nums.size()-1] +=1;
            k--;
        }
        return sum;
    }
};
int main()
{
    return 0;
}