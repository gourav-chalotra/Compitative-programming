#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestCombination(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int max = arr[arr.size() - 1];
        int size = 0;
        unordered_map<int, int> mp;
        while (max)
        {
            max = max >> 1;
            size++;
        }
        max = arr[arr.size() - 1];
        arr[arr.size() - 1] = 0;

        vector<int> binaryValues(size, 0);

        
        for (int i = binaryValues.size() - 1; i >= 0 && max; i--)
        {
            binaryValues[i] = max & 1;
            max = max >> 1;
        }


        for (int i = 0; i < binaryValues.size(); i++)
        {
            if (max < binaryValues[i])
            {
                max = binaryValues[i];
            }
            cout << binaryValues[i] << " ";
        }
        cout << endl;

        for (int i = 1; i < arr.size(); i++)
        {
            int cp = arr[i];
            int j = binaryValues.size() - 1;

            while (j >= 0 && cp)
            {
                binaryValues[j] += cp & 1;
                cp = cp >> 1;
                j--;
            }
        }
        max = INT_MIN;
        for (int i = 0; i < binaryValues.size(); i++)
        {
            if (max < binaryValues[i])
            {
                max = binaryValues[i];
            }
            cout << binaryValues[i] << " ";
        }

        return max;
    }
};
int main()
{
    Solution solution;
    vector<int> arr = {44, 14, 69, 36, 46, 38, 57, 90, 4, 16, 19, 49, 73, 51, 68, 4, 14, 14, 87, 13, 12, 81, 64, 56, 61, 13, 43, 11, 87, 46, 1, 94, 83, 83, 77, 77, 73, 42, 72, 98, 25, 52, 40, 75, 31, 37, 35, 26, 6, 29, 89, 40, 66, 32, 56, 61, 50, 93, 22, 64, 73, 77, 3, 77, 70, 7, 53, 23, 45, 49, 29, 34};
    cout << solution.largestCombination(arr);
}