#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, j = 0;
        string s;
        for (; i < chars.size(); i)
        {
            j = i + 1;
            int check = 0;
            for (; j < chars.size(); j++)
            {
                if (chars[i] != chars[j])
                {
                    break;
                }
            }
            s += chars[i];
            check = j - i;
            i = j;
            if (check > 1)
            {
                stack<char> stk;
                while (check)
                {
                    stk.push('0' + (check % 10));
                    check -= (check % 10);
                    check /= 10;
                }
                while (!stk.empty())
                {
                    s += stk.top();
                    stk.pop();
                }
            }
        }
        chars.clear();
        for (int i = 0; i < s.size(); i++)
            chars.push_back(s[i]);

        return s.size();
    }
};
int main()
{
    vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}; // a2b2c3
    Solution s1;
    cout << s1.compress(s);
}