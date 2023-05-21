#include <iostream>
using namespace std;
class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        if (s.size() == 1 || s.size() == 0)
        {
            return s;
        }
        else
        {
            int i = 0, j = s.size() - 1;
            while (i <= j)
            {
                if(s[i] == s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    s[i] = s[j];
                    i++;
                    j--;
                }
                
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    cout << s.makeSmallestPalindrome("ehtlltoe");
}