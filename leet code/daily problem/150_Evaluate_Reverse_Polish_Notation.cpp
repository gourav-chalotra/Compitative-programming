#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> opt;
        int ans = 0;
        if (tokens.size() == 1)
        {
            return stoi(tokens[0]);
        }
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/")
            {
                    int firstNum = opt.top();
                    opt.pop();
                    int secondNum = opt.top();
                    opt.pop();
                    if(tokens[i] == "-")
                    {
                        ans = firstNum-secondNum;
                        opt.push(ans);
                    }
                    else if(tokens[i] == "+")
                    {
                        ans = firstNum+secondNum;
                        opt.push(ans);
                    }
                    else if(tokens[i] == "*")
                    {
                        ans = firstNum*secondNum;
                        opt.push(ans);
                    }
                    else if(tokens[i] == "/")
                    {
                        ans = secondNum/firstNum;
                        opt.push(ans);
                    }
            }
            else
            {
                int num = stoi(tokens[i]);
                opt.push(num);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> str = {"-200", "1", "+", "200", "*"};
    s.evalRPN(str);
}