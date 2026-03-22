#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        vector<int> num2;
        sort(nums1.begin(), nums1.end());
        unordered_map<int, int> odd, even;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] % 2 == 0)
            {
                even[nums1[i]] = i;
            }
            else
            {
                odd[nums1[i]] = i;
            }
        }
        // odd
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] % 2 == 1)
                num2.push_back(nums1[i]);
            else
            {
                for (auto j : odd)
                {
                    if (j.first % 2 == 1 && j.second != i && nums1[i] - j.first >= 1)
                    {
                        num2.push_back(nums1[i] - j.first);
                        // cout << "j.first: "<< j.first << endl;
                    }
                }
            }
        }
        for (auto i : num2)
        {
            cout << i << " ";
        }
        cout << endl;
        bool check = true;
        if (num2.size() != nums1.size())
        {
            check = false;
        }
        if (check)
        {
            return check;
        }
        else
        {
            num2.clear();
            // even
            for (int i = 0; i < nums1.size(); i++)
            {
                if (nums1[i] % 2 == 0)
                {
                    num2.push_back(nums1[i]);
                }
                else
                {
                    for (auto j : odd)
                    {
                        if (j.first % 2 == 1 && j.second != i && nums1[i] - j.first >= 1)
                        {
                            num2.push_back(nums1[i] - j.first);
                            // cout << "j.first: "<< j.first << endl;
                        }
                    }
                }
            }
            check = true;
            if (num2.size() != nums1.size())
            {
                check = false;
            }
        }
        return check;
    }
};
int main()
{
    vector<int> num = {4,6};
    Solution s;
    cout << s.uniformArray(num);
}