#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int i = 1, max = 0;
        sort(arr.begin(), arr.end());
        if (arr[0] != 1)
            arr[0] = 1;
        while (i < arr.size())
        {
            if (arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;
            i++;
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2, 2, 1, 2, 1};

    cout << s.maximumElementAfterDecrementingAndRearranging(arr);
}