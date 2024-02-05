// 75. Sort Colors
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int NumOfZeros = 0,NumOfOnes = 0, NumOfTwos = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                NumOfOnes++;
            else if(nums[i] == 2)
                NumOfTwos++;
            else
                NumOfZeros++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(NumOfZeros)
            {
                nums[i] = 0;
                NumOfZeros--;
            }
            else if(NumOfOnes)
            {
                nums[i] = 1;
                NumOfOnes--;
            }
            else if(NumOfTwos){
                nums[i] = 2;
                NumOfTwos--;
            }
        }        
    }
};
