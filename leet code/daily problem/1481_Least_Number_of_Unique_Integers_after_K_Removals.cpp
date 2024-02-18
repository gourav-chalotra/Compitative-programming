// 1481. Least Number of Unique Integers after K Removals
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        // using unordered_map we find the no. of unique elements
        unordered_map<int, int> mp;
        // iterate on array
        for (auto i : arr)
            mp[i]++;
        // one time occurrence of element
        vector<int> SortArray;
        for (auto i : mp)
        {
            SortArray.push_back(i.second);
        }
        // sort the SortArray
        sort(SortArray.begin(), SortArray.end());
        // check while k
        int size = SortArray.size(), i = 0;
        while (i < SortArray.size() && k > 0)
        {
            if (k - SortArray[i] >= 0)
            {
                k -= SortArray[i];
                size--;
            }
            i++;
        }
        return size;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {1};
    cout << s.findLeastNumOfUniqueInts(arr, 1);
}