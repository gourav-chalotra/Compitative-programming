// Question link: https://leetcode.com/problems/sort-array-by-parity/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans = {nums[0]};
        for(int i = 1; i < nums.size(); i++)
            if(nums[i]%2 == 0)
                ans.insert(ans.begin(),nums[i]);
            else
                ans.push_back(nums[i]);
        return ans;
    }
};
int main()
{

}