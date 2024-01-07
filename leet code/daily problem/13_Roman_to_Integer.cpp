#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int intValue = 0;
        int i;
        for(i = 0; i < s.size()-1; i)
        {
            if(mp[s[i]] < mp[s[i+1]])
            {
                intValue += mp[s[i+1]]-mp[s[i]];
                i+=2;
            }
            else
            {
                intValue += mp[s[i]];
                i++;
            }
        }
        if(i == s.size()-1)
        {
            intValue += mp[s[i]];
        }
        return intValue;
    }
};
int main()
{
    
}