#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int checkDay(vector<int> &weights, int mid, int days)
    {
        int NeededDays = 1, checkWeight = 0;
        int i = 0;
        while (i < weights.size())
        {
            checkWeight = checkWeight + weights[i];
            if (checkWeight > mid)
            {
                NeededDays++;
                checkWeight = weights[i];
            }
            i++;
        }
        if (NeededDays <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxWeightArr = 0, weightSum = 0, ShipCapacity = 0;
        int i = 0;
        while (i < weights.size())
        {
            if (weights.at(i) > maxWeightArr)
            {
                maxWeightArr = weights.at(i);
            }
            weightSum = weightSum + weights.at(i);
            i++;
        }
        cout << "\n\n";

        int L = maxWeightArr, R = weightSum, mid, result;
        while (L <= R)
        {
            mid = L + (R - L) / 2;
            ShipCapacity = checkDay(weights, mid, days);
            if (ShipCapacity)
            {
                result = mid;
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v = {10, 50, 100, 100, 50, 100, 100, 100};
    cout << s.shipWithinDays(v, 5);
    return 0;
}