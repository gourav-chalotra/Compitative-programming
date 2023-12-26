#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
            {
                stk.pop();
            }
            else
            {
                stk.push(s.at(i));
            }
        }
        string reversString,ans;
        while(!stk.empty())
        {
            reversString+=(stk.top());
            stk.pop();
        }
        for(int i = reversString.size()-1; i>=0 ;i--)
        {
            ans.push_back(reversString.at(i));
        }
        return ans;
    }
};
    int main()
    {
        Solution s;
        string name = "G*ouaa*vChalotra*a";
        cout << s.removeStars(name);
        return 0;
    }