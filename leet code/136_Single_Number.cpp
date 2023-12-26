#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int frount = 0, last = nums.size()-1;
        while(frount < last)
        {
            if(nums[frount] == nums[frount+1])
            {
                int valF = nums[frount];
                while(nums[frount] == valF)
                {
                    frount++;
                }
            }
            if(nums[last] == nums[last-1])
            {
                int valL = nums[last];
                while(nums[last]==valL)
                {
                    last--;
                }
            }
        }
        return nums[frount];
    }
};
int main()
{
    
}