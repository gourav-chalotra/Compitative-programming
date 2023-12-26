#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int i = 0, last = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int max = -100000;
        while (i < last)
        {
            max = (nums[i] + nums[last] > max) ? nums[i] + nums[last] : max;
            last--;
            i++;
        }
        return max;
    }
};
int main()
{
    Solution s;
    vector<int> num = {3, 5, 4, 2, 4, 6};
    vector<int>::iterator it = num.begin();
    cout << "vector value is: ";
    while (it != num.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << "\nAnd the minimum pair sum is : " << s.minPairSum(num) << endl;
    return 0;
}