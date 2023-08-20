#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(s.size() != words.size())
            return false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != words[i][0])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}