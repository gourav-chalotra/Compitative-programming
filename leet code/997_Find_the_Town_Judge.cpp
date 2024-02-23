#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[i];
            cout << mp[i].size() << endl;
        }

        for (int i = 0; i < trust.size(); i++)
        {
            mp[trust[i][0]].push_back(trust[i][1]);
        }
        for (auto i : mp)
        {
            cout << "i :- " << i.first << endl;
            for (int j = 0; j < i.second.size(); j++)
            {
                cout << i.second[j] << " ";
            }
            cout << "\n\n"
                 << endl;
        }
        int townJudge = -1;
        for (auto i : mp)
        {
            if (i.second.size() == 0)
            {
                townJudge = i.first;
                break;
            }
        }
        cout << "townJudge: " << townJudge << endl;
        if (townJudge == -1)
            return -1;

        for (auto i : mp)
        {
            int find = false;
            if (i.first == townJudge)
                continue;
            for (int j = 0; j < i.second.size(); j++)
            {
                if (i.second[j] == townJudge)
                {
                    find = true;
                    break;
                }
            }
            if (find == false)
                return -1;
        }
        return townJudge;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v2 = {{1, 3}, {2, 3}, {3, 1}};
    cout << s.findJudge(3, v2);
}