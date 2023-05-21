#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;
        int i = 0;
        while (i < s.size())
        {
            if (!st.empty() && st.top() == 'A' && s[i] == 'B' || !st.empty() && st.top() == 'C' && s[i] == 'D')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};
int main()
{
    Solution s;
    cout << s.minLength("ACBBD");
}