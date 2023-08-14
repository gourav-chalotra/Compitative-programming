#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        map<int, int> m;
        int i = 0;
        for (; i < nums.size(); i++)
            m[nums[i]]++;
        for (auto i : m)
        {
            cout << "i.first: " << i.first << " i.second: " << i.second << endl;
        }
        map<int, int>::reverse_iterator it;

        for(it = m.rbegin(); it!=m.rend(); it++)
        {
            k-=it->second;
            if(k <= 0)
                break;
        }
        return it->first;
    }
};

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    Solution s;
    cout << s.findKthLargest(nums, 20);
}