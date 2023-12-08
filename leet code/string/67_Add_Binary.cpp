#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        char c = '0';
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (a[i] == '1' && b[j] == '1')
            {
                if (c == '0')
                {
                    ans.push_back('0');
                }
                else
                {
                    ans.push_back('1');
                }
                c = '1';
            }
            else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
            {
                if (c == '0')
                {
                    ans.push_back('1');
                }
                else
                {
                    ans.push_back('0');
                    c = '1';
                }
            }
            else
            {
                if(c == '1')
                {
                    ans.push_back('1');
                    c = '0';
                }
                else
                    ans.push_back('0');
            }
            i--, j--;
        }
        
        if (j >= 0)
        {
            while (j >= 0)
            {
                if (b[j] == '1')
                {
                    if (c == '1')
                    {
                        ans.push_back('0');
                    }
                    else
                    {
                        ans.push_back('1');
                        c = '0';
                    }
                }
                else
                {
                    if (c == '1')
                    {
                        ans.push_back('1');
                        c = '0';
                    }
                    else
                    {
                        ans.push_back('0');
                        c = '0';
                    }
                }
                j--;
            }
        }
        else if (i >= 0)
        {
            while (i >= 0)
            {
                if (a[i] == '1')
                {
                    if (c == '1')
                    {
                        ans.push_back('0');
                    }
                    else
                    {
                        ans.push_back('1');
                        c = '0';
                    }
                }
                else
                {
                    if (c == '1')
                    {
                        ans.push_back('1');
                        c = '0';
                    }
                    else
                    {
                        ans.push_back('0');
                        c = '0';
                    }
                }
                i--;
            }
        }
        if(c == '1')
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    // 1001001
    cout << s.addBinary("110010", "10111");
    return 0;
}