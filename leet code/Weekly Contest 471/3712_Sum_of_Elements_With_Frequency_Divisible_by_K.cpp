#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum = 0;
        for(auto i : nums)
            mp[i]++;
        
        for(auto i : mp)
        {
            if((i.second%k) == 0)
            {
                sum += (i.second)*i.first;
            }
        }
        return sum;
    }
};
int main()
{
    Solution s;
}