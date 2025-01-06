#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sum(unordered_map<int, int> mp, int x)
    {
        // value based sort
        vector<pair<int, int>> valueBaseSort;
        for (auto i : mp)
        {
            pair<int, int> value{i.first, i.second};
            valueBaseSort.push_back(value);
        }
        cout << "\nvalue's" << endl;
        for (int i = 0; i < valueBaseSort.size(); i++)
        {
            cout << "key: " << valueBaseSort[i].first << " ";
            cout << "value: " << valueBaseSort[i].second << endl;
        }
        cout << "\nfreq sort" << endl;
        int count = 0;
        for (int i = 0; i < valueBaseSort.size() - 1; i++)
        {
            for (int j = i + 1; j < valueBaseSort.size(); j++)
            {
                if (valueBaseSort[i].second < valueBaseSort[j].second)
                {
                    swap(valueBaseSort[i], valueBaseSort[j]);
                    count++;
                }
            }
        }
        if (count < x)
        {
            for (int i = count; i < valueBaseSort.size(); i++)
            {
                cout << "key: " << valueBaseSort[i].first << " ";
                cout << "value: " << valueBaseSort[i].second << endl;
            }

            cout << "\nvalue based sort" << endl;
            for (int i = count; i < valueBaseSort.size() - 1; i++)
            {
                for (int j = i + 1; j < valueBaseSort.size(); j++)
                {
                    if (valueBaseSort[i].first < valueBaseSort[j].first)
                    {
                        swap(valueBaseSort[i], valueBaseSort[j]);
                    }
                }
            }
            for (int i = 0; i < valueBaseSort.size(); i++)
            {
                cout << "key: " << valueBaseSort[i].first << " ";
                cout << "value: " << valueBaseSort[i].second << endl;
            }
        }

        int sum = 0;
        for (int i = 0; i < valueBaseSort.size() && x; i++, x--)
        {
            cout << "valueBaseSort[i].first * valueBaseSort[i].second: " << valueBaseSort[i].first * valueBaseSort[i].second << endl;
            sum += (valueBaseSort[i].first * valueBaseSort[i].second);
        }
        cout << "sum: " << sum << endl;
        return sum;
    }
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        vector<int> ans;

        if (x >= nums.size())
        {
            int sumArr = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sumArr += nums[i];
            }
            ans.push_back(sumArr);
            return ans;
        }

        for (int i = 0; i <= nums.size() - k; i++)
        {
            int j = i;
            unordered_map<int, int> mp;
            for (; (j < k + i) && j < nums.size() && ((k + i) <= nums.size()); j++)
            {
                mp[nums[j]]++;
            }
            ans.push_back(sum(mp, x));
        }
        return ans;
    }
};
int main()
{
    vector<int> a = {5, 5, 4, 3, 1, 3, 1, 3, 4, 6, 4, 2};
    Solution s;
    vector<int> ans = s.findXSum(a, 10, 2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }
}