#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums.size()/2, maxval = INT_MIN;
        map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
            if(mp[i] > val)
            {
                maxval = i;
            }
        }
        return maxval;
    }
};

int main()
{
    
    return 0;
}