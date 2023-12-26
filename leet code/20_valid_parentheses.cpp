// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> charStk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
            {
                charStk.push(s.at(i));
            }
            else if (!charStk.empty() && (charStk.top() == '{' && s.at(i) == '}' || charStk.top() == '[' && s.at(i) == ']' || charStk.top() == '(' && s.at(i) == ')'))
            {
                charStk.pop();
            }
            else
            {
                return false;
            }
        }
        return (charStk.empty()) ? true : false;
    }
};
int main()
{

    Solution s;
    string parentheses = "{{[}]}";
    cout << s.isValid(parentheses);

    return 0;
}