#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                // cout << "arr[ " << i << "] = " << arr[i] << endl;
                for (int j = arr.size() - 1; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> num = {1, 0, 2, 3, 0, 4, 5, 0};
    s.duplicateZeros(num);
}