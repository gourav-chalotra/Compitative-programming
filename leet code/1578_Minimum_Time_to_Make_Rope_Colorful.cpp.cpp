#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int i = 0, j = 0, time = 0;
        while (i < neededTime.size() && j < neededTime.size())
        {
            int totalCurr = 0, CurrMax = 0;
            while (colors[i] == colors[j])
            {
                totalCurr += neededTime[j];
                CurrMax = max(CurrMax, neededTime[j]);
                j++;
            }
            time += (totalCurr - CurrMax);
            i = j;
        }
        return time;
    }
};
int main()
{
    string colors = "aabaa";
    vector<int> need = {1, 2, 3, 4, 1};
    Solution s;
    cout << s.minCost(colors, need);
}