// LEVEL HARD

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int sizeNums1 = nums1.size();
        int sizeNums2 = nums2.size();

        vector<int> mearge;
        for (auto i : nums1)
        {
            mearge.push_back(i);
        }
        for (auto i : nums2)
        {
            mearge.push_back(i);
        }
        sort(mearge.begin(),mearge.end());
        int size = mearge.size();
        double a = 0;
        if(size%2 == 0)
        {   
            a = double((mearge.at(size/2-1)+mearge.at(size/2+1-1)))/(double)2;
        }
        else if(size%2 == 1)
        {   
            a = (double)mearge.at(size/2);
        }
        return a;
    }
};
int main()
{
    Solution s;
    vector<int> num = {1,2};
    vector<int> num1 = {3,4};
    double ans = s.findMedianSortedArrays(num,num1);
    cout << "ans: " << ans << endl;
    return 0;
}