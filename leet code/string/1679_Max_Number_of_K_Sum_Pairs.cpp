#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == k)
            {
                count++;
                j--;
                i++;
            }
            else if (sum > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};

int main()
{
    
}