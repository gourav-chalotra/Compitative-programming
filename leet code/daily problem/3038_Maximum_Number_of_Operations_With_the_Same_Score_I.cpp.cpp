#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = nums[0]+nums[1];
        int num = 1;
        for(int i = 2; i < nums.size()-1; i+=2)
        {
            if(nums[i] + nums[i+1] == score)
            {
                num++;
            }
            else
                break;
        }
        return num;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1,10,100};
    vector<int> v1 = {1000};
    cout << s.maxOperations(v);
}