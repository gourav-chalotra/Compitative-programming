#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(long dividend, long divisor)
    {
        int checkneg = 0;
        if (dividend < 0)
        {
            dividend *= -1;
            checkneg++;
        }
        if (divisor < 0)
        {
            divisor = -(divisor);
            checkneg++;
        }
        if (dividend == divisor || divisor == 1)
        {
            if (checkneg == 2)
                return dividend;
            else if (checkneg)
                return dividend*-1;
            return dividend;
        }
        long long sum = 0;
        while (dividend > divisor)
        {
            int k = 0, val = 0;
            while ((divisor << k) < dividend)
            {
                val = (divisor << k);
                k++;
            }
            k--;
            cout << k << endl;
            sum += pow(2, k);
            //  1  1 0
            //  4 2 1
            cout << "sum: "<< sum << endl;
            dividend = dividend - val;
        }
        if (checkneg == 2)
            return sum;
        else if (checkneg)
            return sum * -1;
        if(sum > pow(2,31)-1)
        {
            return pow(2,31)-1;
        }
        else if(sum < pow(-2,31))
        {
            return pow(-2,31);
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.divide(12323, 1);
}