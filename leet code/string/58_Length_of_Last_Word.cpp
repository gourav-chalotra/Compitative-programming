#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size();
        int count = 0;
        while(i--)
        {
            if(s[i] != ' ')
            {
                count++;
            }
            else if(s[i] == ' ' && count == 0)
                continue;
            else
                break;
            
        }
        return count;
    }
};

int main()
{
    return 0;
}