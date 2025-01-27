#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<char, bool> operators = {{'+', true}, {'-', true}, {'*', true}, {'/', true}};

    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> res = {};
        for (int i = 0; i < expression.size(); i++)
        {
            if (operators[expression[i]])
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, (i)));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, (expression.size() - (i + 1))));
                cout << "i: " << i << endl;
                cout << "left[0]: " << left[0] << endl;
                cout << "right[0]: " << right[0] << endl;

                for (int k = 0; k < left.size(); k++)
                {
                    for (int j = 0; j < right.size(); j++)
                    {
                        if (expression[i] == '*')
                        {
                            res.push_back(left[k] * right[j]);
                        }
                        else if (expression[i] == '-')
                        {
                            res.push_back(left[k] - right[j]);
                        }
                        else if (expression[i] == '/')
                        {
                            res.push_back(left[k] / right[j]);
                        }
                        else if (expression[i] == '+')
                        {
                            res.push_back(left[k] + right[j]);
                        }
                    }
                }
            }
        }
        if (res.empty())
        {
            res.push_back(stoi(expression));
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "2*3-4*5";
    vector<int> ans = s.diffWaysToCompute(str);
    cout << "\n After function call \n"
         << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "ans[i]: " << ans[i] << endl;
    }
}