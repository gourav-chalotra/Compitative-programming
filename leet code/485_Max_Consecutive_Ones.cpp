#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = 0, maxSub1 = 0, count = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                if (count > maxSub1)
                {
                    maxSub1 = count;
                }
                count = 0;
            }
            else
                count++;
            i++;
        }
        if (count > maxSub1)
        {
            maxSub1 = count;
        }
        return maxSub1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0};
    cout << s.findMaxConsecutiveOnes(v);
    return 0;
}