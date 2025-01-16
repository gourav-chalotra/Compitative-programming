#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int num1Size = nums1.size();
        int num2Size = nums2.size();

        int xor1 = 0,xor2 = 0;
        if(num1Size%2)
        {
            for(auto i : nums2){
                xor1 ^= i;
            }
        }
        if(num2Size%2)
        {
            for(auto i : nums1)
            {
                xor2 ^= i;
            }
        }
        return xor1^xor2;
    }
};

int main()
{
    Solution s;
    vector<int>num1 = {2,1,3};
    vector<int>num2 = {10,2,5,0};
    cout << s.xorAllNums(num1, num2);
}