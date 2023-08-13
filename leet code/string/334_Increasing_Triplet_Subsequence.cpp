#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int low = INT_MAX, mid = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > mid)
                return true;
            else if(nums[i] < low)
                low = nums[i];
            else if(nums[i] < mid && nums[i] > low)
                mid = nums[i];
        }
        return false;
    }
};

int main()
{

}