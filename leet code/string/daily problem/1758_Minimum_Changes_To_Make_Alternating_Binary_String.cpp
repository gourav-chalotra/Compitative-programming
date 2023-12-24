#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        char ones = '1', zero = '0';
        int countOnesMatch = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ones)
                countOnesMatch++;
            ones = (ones == '1') ? '0' : '1';
            zero = (zero == '1') ? '0' : '1';
        }
        int size = s.size();
        return (s.size() - max(countOnesMatch,(size-countOnesMatch)));
    }
};
int main()
{
    Solution s;
    s.minOperations("0100");
}