#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = n-1;
        // we have to sort the array
        sort(nums.begin(),nums.end());
        vector<int> pow(n,1);
        for(int i = 1; i<n; i++)
            pow[i] = pow[i-1] * 2 % 1000000007;

        while(l <= r){
            if(nums[l] + nums[r] > target) r--;
            else{
                ans = (ans + pow[r - l++]) % 1000000007;
            }
        }
        return ans % 1000000007;
    }
};
int main()
{
	vector<int>nums = {14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14};
	int target = 22;
	Solution s;
	cout << s.numSubseq(nums, target);
	return 0;
}

// This code is contributed by mohit kumar 29
