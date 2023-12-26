#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>mp;
        int i = 0;
        while(i < s.size())
        {
            mp[s[i]]++;
            if(mp[s[i]] == 2)
                return s[i];
            i++;
        }
        return 'a';
    }
};
int main()
{
    
}