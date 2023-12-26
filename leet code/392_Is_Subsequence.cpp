#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        stack<char> chars;
        int i = s.size() - 1;
        for (i; i >= 0; i--)
        {
            chars.push(s[i]);
        }
        i = 0;
        for (; i < t.size() && !chars.empty(); i++)
        {
            if (chars.top() == t[i])
            {
                chars.pop();
            }
        }
        return (chars.empty()) ? true : false;
    }
};
int main()
{
    Solution s;
    cout << s.isSubsequence("axc", "ahbgdc");
    return 0;
}