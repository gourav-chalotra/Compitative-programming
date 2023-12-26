#include <iostream>
#include <vector>
#include <set>
class Solution
{
public:
    std::vector<std::vector<int>> findDifference(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<std::vector<int>> ans(2, std::vector<int>(0));
        std::set<int> s1, s2;
        for (int i : nums1)
        {
            s1.insert(i);
        }

        for (int i : nums2)
        {
            s2.insert(i);
        }

        nums1.clear();
        nums2.clear();

        for (auto t : s1)
        {
            nums1.push_back(t);
        }
        for (auto t : s2)
        {
            nums2.push_back(t);
        }

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                ans[0].push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] == nums2[j])
            {
                i++;
                j++;
            }
            else
            {
                ans[1].push_back(nums2[j]);
                j++;
            }
        }
        if (j != nums2.size())
        {
            while (j < nums2.size())
            {
                ans[1].push_back(nums2[j]);
                j++;
            }
        }
        else if (i != nums1.size())
        {
            while (i < nums1.size())
            {
                ans[0].push_back(nums1[i]);
                i++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    std::vector<int> nums1 = {1, 3, 5, 2, 2, 2, 2, 3}, nums2 = {3, 4, 6, 7, 2, 4, 6};
    s.findDifference(nums1, nums2);
}