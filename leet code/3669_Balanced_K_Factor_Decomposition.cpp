#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minDifference(int n, int k)
    {
        // We need to find the factores of n.
        vector<int> factores;
        int minVal = n - 1;
        vector<int> ans;
        while (n)
        {
            bool div = false;
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    factores.push_back(i);
                    n = (int)n / i;
                    div = true;
                    break;
                }
            }
            if (!div)
            {
                factores.push_back(n);
                break;
            }
        }
        cout << "factor: ";
        for (auto i : factores)
        {
            cout << i << " ";
        }
        while (!(k == factores.size()))
        {
            
        }
        cout << endl;
        return ans;
    }
};

int main()
{
    Solution s;

    s.minDifference(100, 2);
}