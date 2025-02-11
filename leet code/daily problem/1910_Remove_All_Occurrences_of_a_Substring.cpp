#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(part.size() > s.size())
            return s;
        
        int i = 0, j = part.size();
        while( i <= s.size() && j <=  s.size())
        {
            string a(s.begin()+i, s.begin()+j);
            if(a == part)
            {
                string newstr = "";
                int k = 0;
                while(k < s.size())
                {
                    if(k < i || k >= j)
                        newstr = newstr + s[k];
                    k++;
                }
                s = newstr;
                i = 0;
                j = part.size();
            }
            else
            {
                i++;
                j++;
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "axxxxyyyyb";
    string part = "xy";
    cout << s.removeOccurrences(str,part);
}