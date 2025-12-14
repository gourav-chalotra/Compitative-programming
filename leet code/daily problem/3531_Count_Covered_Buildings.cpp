#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        int count = 0;
        unordered_map<int, pair<int, int>> rowCity;
        unordered_map<int, pair<int, int>> colCity;

        for (int i = 0; i < buildings.size(); i++)
        {
            if (!rowCity.count(buildings[i][0]))
            {
                rowCity[buildings[i][0]] = {buildings[i][1],buildings[i][1]};
            }
            else
            {
                rowCity[buildings[i][0]].first = min(rowCity[buildings[i][0]].first, buildings[i][1]);
                rowCity[buildings[i][0]].second = max(rowCity[buildings[i][0]].second, buildings[i][1]);
            }
            if (!colCity.count(buildings[i][1]))
            {
                colCity[buildings[i][1]] = {buildings[i][0],buildings[i][0]};
            }
            else
            {
                colCity[buildings[i][1]].first = min(colCity[buildings[i][1]].first, buildings[i][0]);
                colCity[buildings[i][1]].second = max(colCity[buildings[i][1]].second, buildings[i][0]);
            }

            rowCity[buildings[i][0]].first = min(rowCity[buildings[i][0]].first, buildings[i][1]);
            rowCity[buildings[i][0]].second = max(rowCity[buildings[i][0]].second, buildings[i][1]);

            colCity[buildings[i][1]].first = min(colCity[buildings[i][1]].first, buildings[i][0]);
            colCity[buildings[i][1]].second = max(colCity[buildings[i][1]].second, buildings[i][0]);
        }
        for (int i = 0; i < buildings.size(); i++)
        {
            bool rCheck = false, cCheck = false;
            int rMin = rowCity[buildings[i][0]].first;
            int rMax = rowCity[buildings[i][0]].second;
            if (rMax != rMin && rMin != buildings[i][1] && rMax != buildings[i][1])
            {
                rCheck = true;
            }
            int cMin = colCity[buildings[i][1]].first;
            int cMax = colCity[buildings[i][1]].second;
            if (cMax != cMin && cMin != buildings[i][0] && cMax != buildings[i][0])
            {
                cCheck = true;
            }
            if (rCheck && cCheck)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> b = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
    cout << s.countCoveredBuildings(3, b);
}