#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ones = 0,zero,i,mx = 0;
        for(i = 0; i < s.size(); i++)
            if(s[i] == '1')
                ones++;
        zero = s.size()-ones;
        if(ones == s.size())
            return ones-1;
        else if(zero == s.size())
            return zero-1;
        int countZ = 0;
        for(i = 0; i < s.size()-1; i++)
        {
            if(s[i] == '1')
                ones--;
            if(s[i] == '0')
            {
                countZ++;
            }
            mx = max(countZ+ones,mx);
        }       
        return mx; 
    }
};

int main()
{
    Solution s;
    cout << s.maxScore("001001");
    return 0;
}