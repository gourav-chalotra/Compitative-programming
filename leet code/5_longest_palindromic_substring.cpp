
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return s;
        string ans;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                string check;
                if (s[i] == s[j] && ans.size() < j - i + 1)
                {
                    int k = j;
                    int l = i;
                    k--,l++;
                    while(l<=k)
                    {
                        if(s[l]!=s[k])
                            break;
                        l++;
                        k--;
                    }
                    if(l>k)
                    {
                        string s1(s.begin()+i,s.begin()+j+1);
                        ans = s1;
                    }
                }
            }
        }
        return (ans.size() == 0) ? ans.push_back(s.at(0)), ans : ans;
    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("a");
    return 0;
}