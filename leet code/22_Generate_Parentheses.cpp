// Problem : https://leetcode.com/problems/generate-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>ans;
    void NoOfValidParentheses(int n,string s)
    {
        if(s.size() == n*2)
        {
            stack<char>stk;
            int i = 0;
            while(i < s.size())
            {
                if(stk.empty())
                {
                    stk.push(s[i]);
                }
                else if(stk.top() == '(' && s[i] == ')')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
                i++;
            }
            if(stk.empty())
            {
                cout << s << endl;
                ans.push_back(s);
            }
            return;
        }
        NoOfValidParentheses(n,s+"(");
        NoOfValidParentheses(n,s+")");
    }
    vector<string> generateParenthesis(int n) {
        NoOfValidParentheses(n,"");
        return ans;
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
}