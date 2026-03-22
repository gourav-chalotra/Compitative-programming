#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        vector<int> num2;
        // even
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] % 2 == 0)
            {
                num2.push_back(nums1[i]);
                continue;
            }
            else
            {
                for (int j = 0; j < nums1.size(); j++)
                {
                    if (j == i)
                        continue;
                    if (nums1[j] % 2 == 1 && nums1[i] % 2 == 1)
                    {
                        num2.push_back(nums1[i] - nums1[j]);
                        break;
                    }
                }
            }
        }
        for(auto i : num2)
            cout << i << " ";
        cout << endl;
        bool check = true;
        if (num2.size() != nums1.size())
            check = false;

        if (!check)
        {
            num2.clear();
            // odd
            for (int i = 0; i < nums1.size(); i++)
            {
                if (nums1[i] % 2 == 1)
                {
                    num2.push_back(nums1[i]);
                    continue;
                }
                else
                {
                    for(int j = 0; j < nums1.size(); j++)
                    {
                        if(nums1[j]%2 == 1 && nums1[i]%2 == 0){
                            num2.push_back(nums1[i]-nums1[j]);
                        }
                    }
                }
            }
        }
        for(auto i : num2)
        {
            cout << i << " ";
        }
        cout << endl;

        if (num2.size() == nums1.size())
            check = true;
        return check;
    }

};
int main()
{
    vector<int> num = {2, 3};
    Solution s;
    cout << s.uniformArray(num);
}