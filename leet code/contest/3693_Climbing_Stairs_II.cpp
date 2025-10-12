#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalMinCost(int pos, vector<int> &costs, int totalCost)
    {
        if (pos == costs.size() - 1)
        {
            return totalCost;
        }
        else if(pos > costs.size()-1)
            return INT_MAX;
        long long first,second,third;
        if (pos + 1 <= costs.size() - 1)
            first = totalMinCost(pos + 1, costs, totalCost + (costs[pos + 1] + pow(((pos + 1) - pos), 2)));
        if (pos + 2 <= costs.size() - 1)
            second = totalMinCost(pos + 2, costs, totalCost + (costs[pos + 2] + pow(((pos + 2) - pos), 2)));
        if (pos + 3 <= costs.size() - 1)
            third = totalMinCost(pos + 3, costs, totalCost + (costs[pos + 3] + pow(((pos + 3) - pos), 2)));
        return min(first,min(second,third));
    }
    int climbStairs(int n, vector<int> &costs)
    {
        int postion = 0, minCost = 0;
        totalMinCost(postion, costs, minCost);
    }
};
int main()
{
    Solution s;
    int n = 4;
    vector<int> cost = {1, 2, 3, 4};
    cout << "Total cost " << s.climbStairs(n, cost);
}