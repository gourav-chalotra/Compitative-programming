#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        double AvgMax = INT_MIN;
        int sum = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            if (j >= k-1)
            {
                double avg = (double)sum / (double)k;
                if (avg > AvgMax)
                {
                    AvgMax = avg;
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (double)AvgMax;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 12, -5, -6, 50, 3};
    cout << s.findMaxAverage(nums, 4);

    return 0;
}