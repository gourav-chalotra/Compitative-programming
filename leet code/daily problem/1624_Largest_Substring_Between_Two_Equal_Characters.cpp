// 1624. Largest Substring Between Two Equal Characters
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int length = -1, i = 0, j = s.size()-1;
        while(i < s.size())
        {
            while(j > i)
            {
                if(s[i] == s[j])
                {
                    length = max(length, j-i-1);
                    break;
                }
                j--;
            }
            j = s.size()-1;
            i++;
        }
        return length;
    }
};
int main()
{
    
}