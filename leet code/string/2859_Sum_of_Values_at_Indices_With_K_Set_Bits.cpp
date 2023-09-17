#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int SumOfVal = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long copI = i, NoOFBits = 0;
            while(copI)
            {
                if(copI & 1 == 1)
                    NoOFBits++;
                copI = copI>>1;
            }
            if(NoOFBits == k)
                SumOfVal += nums[i];
        }
        return SumOfVal;
    }
};
int main()
{
    return 0;
}