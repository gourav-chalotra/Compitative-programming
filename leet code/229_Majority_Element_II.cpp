#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int i = 0;
        while (i < nums.size())
            mp[nums[i++]]++;
        i = 0;
        vector<int> ans;
        map<int,int>::iterator it = mp.begin();
        while(it!=mp.end())
        {
            if(it->second > nums.size()/3)
                ans.push_back(it->first);
            it++;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3};
    Solution s;
    vector<int> v = s.majorityElement(nums);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}