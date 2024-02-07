#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        int maxVal = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            maxVal = (mp[s[i]] > maxVal) ? mp[s[i]] : maxVal;
        }
        vector<pair<char, int>> arr;
        pair<char, int> vl;
        for (auto i : mp)
        {
            arr.push_back(i);
        }
        // Sort
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i].second > arr[j].second)
                {
                    pair<char, int> temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        string newAns;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while(arr[i].second)
            {
                newAns += arr[i].first;
                arr[i].second--;
            }
        }
        cout << newAns;
    }
};
int main()
{
    Solution s;
    s.frequencySort("tree");
}