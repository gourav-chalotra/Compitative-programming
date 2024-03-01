#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end());
        int i = 0,l = s.size()-2;
        while(l > i)
        {
            if(s[i] == '0' && s[l] == '1'){
                swap(s[i],s[l]);
                i++,l--;
            }
            else if(s[i] == '1')
            {
                break;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    cout << s.maximumOddBinaryNumber("010");
}