#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int i = 0, j = 0, sum = 0, length = 0, currentLength = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            if (sum + 1 >= j - i + 1)
            {
                j++;
                continue;
            }
            else
            {
                cout << "J: " << j << endl;
                currentLength = j - i;
                if (length < currentLength)
                    length = currentLength-1;
                if (nums[i] == 1)
                    sum--;
                i++;
                j++;
            }
        }
        currentLength = j - i;
        if (length < currentLength)
            length = currentLength-1;
        return length;
    }
};
    int main()
    {

        vector<int> nums = {1,1,1};
        Solution s;
        cout << s.longestSubarray(nums);
        return 0;
    }