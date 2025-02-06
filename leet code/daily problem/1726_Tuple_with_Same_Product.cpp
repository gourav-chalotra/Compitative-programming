#include <bits/stdc++.h>
using namespace std;

struct pair_heap
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 * 31);
    }
};

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int count = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (j == i)
                    continue;
                mp[nums[i]*nums[j]]++;
            }
        }
        int sum = 0;
        
        for(auto i : mp)
        {
            if(i.second > 1)
                sum += (i.second*(i.second-1))/2;
        }

        return sum*8;
    }
};
int main()
{
    vector<int> nums = {2,3,4,6};
    Solution s;
    cout << s.tupleSameProduct(nums);
}