#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool check(vector<int> v1, int value)
    {
        for (auto a : v1)
        {
            if (a == value)
            {
                return 1;
            }
        }
        return 0;
    }

public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> v1;
        vector<int>::iterator t = nums.begin();

        while (t != nums.end())
        {
            if (!check(v1, *t))
            {
                v1.push_back(*t);
            }
            t++;
        }
        int i = 0;
        while (i < v1.size())
        {
            nums[i] = v1[i];
            i++;
        }
        return v1.size();
    }
};
int main()
{
    Solution s;
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    s.removeDuplicates(v);
}