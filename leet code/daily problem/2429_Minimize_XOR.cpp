#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int countOneNum1 = 0, countOneNum2 = 0, countZeroNum1 = 0, countZeroNum2 = 0, ans = 0;
        int tempNum1 = num1, tempNum2 = num2;
        // CountNum1
        while (tempNum1)
        {
            if (tempNum1 & 1)
                countOneNum1++;
            else
                countZeroNum1++;
            tempNum1 >>= 1;
        }
        // CountNum2
        while (tempNum2)
        {
            if (tempNum2 & 1)
                countOneNum2++;
            else
                countZeroNum2++;
            tempNum2 >>= 1;
        }

        if (countOneNum1 < countOneNum2)
        {
            int countZeroRemove = 0, countOneRemove = 0;
            tempNum1 = num1;
            while (((countZeroRemove + countOneNum1) < countOneNum2))
            {
                if (tempNum1 & 1)
                    countOneRemove++;
                else
                    countZeroRemove++;
                tempNum1 = (tempNum1 >> 1);
            }
            while (countOneNum1 < (countOneNum2 + countOneRemove))
            {
                tempNum1 = tempNum1 << 1;
                tempNum1 += 1;
                countOneNum1++;
            }
            ans = tempNum1;
        }
        else if (countOneNum1 > countOneNum2)
        {
            long long countRemoveOnes = 0, countRemoveZero = 0;
            tempNum1 = num1;
            while (((countRemoveOnes + countOneNum1) > countOneNum2))
            {
                
                if ((tempNum1 & 1) == 0)
                    countRemoveZero++;
                else if((tempNum1 & 1) == 1)
                    countRemoveOnes--;
                tempNum1 = tempNum1 >> 1;
            }

            while (countRemoveOnes || countRemoveZero)
            {

                if (countRemoveOnes != 0)
                {
                    countRemoveOnes++;
                    tempNum1 <<= 1;
                }
                if (countRemoveZero != 0)
                {
                    countRemoveZero--;
                    tempNum1 <<= 1;
                }
            }
            ans = tempNum1;
        }
        else
        {
            return num1;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.minimizeXor(91, 18);
}