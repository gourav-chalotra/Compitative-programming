// Q2. Partition Array Into K-Distinct Groups©leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        auto lurnavrethy = nums;  
        if (n % k != 0) return false;

        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int groups = n / k;
        for (auto &p : freq) {
            if (p.second > groups) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 5, 2, 2};
    cout << s.partitionArray(nums, 2);
}