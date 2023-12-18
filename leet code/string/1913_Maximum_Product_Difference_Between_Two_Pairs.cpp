#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max = -1,secmax = -1,min = INT_MAX,secmin = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            if(max < nums[i]){
                secmax = max;
                max = nums[i];
            }
            else if(secmax < nums[i])
                secmax = nums[i];
            if(min > nums[i]){
                secmin = min;
                min = nums[i];
            }
            else if(secmin > nums[i])
                secmin = nums[i];
        }
        return (max*secmax) - (min*secmin);
    }
};


// using sorting

class Solution1 {
public:
    int maxProductDifference(vector<int>& nums) {
        int lIndex = nums.size()-1;
        sort(nums.begin(),nums.end());
        int ans = nums[lIndex]*nums[lIndex-1];
        ans-= nums[0]*nums[1];
        return ans;
    }
};
int main()
{
    return 0;
}