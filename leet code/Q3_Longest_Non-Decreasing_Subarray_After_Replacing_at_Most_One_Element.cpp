#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;   
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; ++i)
        if (nums[i] >= nums[i - 1]) left[i] = left[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
        if (nums[i] <= nums[i + 1]) right[i] = right[i + 1] + 1;

    int ans = 1;
    for (int i = 0; i < n; ++i)
        ans = max(ans, max(left[i], right[i])); // no replacement

    for (int i = 0; i < n; ++i) {
        int L = (i > 0) ? left[i - 1] : 0;
        int R = (i + 1 < n) ? right[i + 1] : 0;

        // replace nums[i] to extend one side
        ans = max(ans, L + 1);
        ans = max(ans, R + 1);

        // replace nums[i] to bridge both sides
        if (i > 0 && i + 1 < n && nums[i - 1] <= nums[i + 1])
            ans = max(ans, L + 1 + R);
    }
    return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,3,5,4,7};
    cout<<s.longestSubarray(nums)<<endl;
    return 0;
}