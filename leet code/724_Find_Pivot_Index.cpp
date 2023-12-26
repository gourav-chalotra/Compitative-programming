#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int rightSum = 0;
            for (int j = i + 1; j < nums.size(); j++)
            {
                rightSum += nums[j];
            }
            int leftSum = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                leftSum += nums[k];
            }
            if (rightSum == leftSum)
                return i;
        }
        return -1;
    }
};

int main()
{
}