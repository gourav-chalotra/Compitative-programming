#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(j < spaces.size() && spaces[j] == i)
            {
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int>index = {5};
    cout<<s.addSpaces("HelloWorld!",index)<<endl;
}