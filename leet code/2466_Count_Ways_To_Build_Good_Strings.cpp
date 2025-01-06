#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int max = 0;
    int fun(int l, int h, string c, string Z, string O)
    {
        if (c.size() > h)
        {
            return 0;
            
        }
        if (c.size() >= l && c.size() <= h)
        {
            max = (max+1)%(1000000007);
        }
        fun( l, h, c + Z, Z, O);
        fun( l, h, c + O, Z, O);
        cout << max << endl;
        return max;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        if(low == high && zero == 1 && one == 1)
        {
            int ans = 2;
            while(high-1)
            {
                ans = (ans * 2)%1000000007;
                high--;
            }
            return ans;

        }
        string Z ="";
        string O = "";
        while(zero)
        {
            Z = Z + "0";
            zero--;
        }
        while(one)
        {
            O = O + "1";
            one--;
        }
        return fun(low, high,"", Z,O);
    }
};
int main()
{
    Solution s;
    cout << s.countGoodStrings(200, 200, 10, 1);
    return 0;
}