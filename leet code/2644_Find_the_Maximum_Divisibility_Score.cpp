// You are given two 0-indexed integer arrays nums and divisors.

// The divisibility score of divisors[i] is the number of indices j such that nums[j] is divisible by divisors[i].

// Return the integer divisors[i] with the maximum divisibility score. If there is more than one integer with the maximum score, return the minimum of them

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int maximumDivisible = 0, index = 0;
        for (int i = 0; i < divisors.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % divisors[i] == 0)
                {
                    count++;
                }
            }
            if (maximumDivisible < count)
            {
                maximumDivisible = count;
                index = i;
            }
            else if (maximumDivisible == count)
            {
                index = (divisors[index] <= divisors[i]) ? index : i;
            }
        }
        return divisors[index];
    }
};
int main()
{
    return 0;
}