#include <iostream>
#include <vector>
class Solution
{
public:
    int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // nums1 front
        int maxOfNum1 = -1, num1Count = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
                if (nums1[i] == nums2[j])
                    if (maxOfNum1 < j)
                    {
                        num1Count++;
                        maxOfNum1 = j;
                        break;
                    }
        }

        // num1 back
        int minIndex = nums1.size(), countBackNums1 = 0;
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
                if (nums1[i] == nums2[j])
                    if (minIndex > j)
                    {
                        countBackNums1++;
                        minIndex = j;
                        break;
                    }
        }

        // nums2 front
        int maxOfNum2 = -1, num2Count = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
                if (nums2[i] == nums1[j])
                {
                    if (maxOfNum2 < j)
                    {
                        maxOfNum2 = j;
                        num2Count++;
                        break;
                    }
                }
        }

        // nums2 back
        int minOfnum2 = nums2.size();
        int countBackNum2 = 0;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            for (int j = nums1.size() - 1; j >= 0; j--)
            {
                if (nums1[j] == nums2[i])
                {
                    if (minOfnum2 > j)
                    {
                        countBackNum2++;
                        minOfnum2 = j;
                        break;
                    }
                }
            }
        }
        int num1 = num1Count, num2 = num2Count, num3 = countBackNums1, num4 = countBackNum2;
        std::cout << "num1: " << num1 << " num2: " << num2 << " num3: " << num3 << " nums4: " << num4 << std::endl;
        int ans;
        if (num1 > num2)
        {
            if (num1 > num3)
            {
                if (num1 > num4)
                {
                    ans = num1;
                }
                else
                    ans = num4;
            }
            else if (num3 > num4)
            {
                ans = num3;
            }
        }
        else if (num2 > num3)
        {
            if (num2 > num4)
            {
                ans = num2;
            }
            else
                ans = num4;
        }
        else
        {
            if (num3 > num4)
            {
                ans = num3;
            }
            else
                ans = num4;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    std::vector<int> num1 = {2, 1};
    std::vector<int> num2 = {1, 2, 1, 3, 3, 2};
    std::cout << s.maxUncrossedLines(num1, num2);
}