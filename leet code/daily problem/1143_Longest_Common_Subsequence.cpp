#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<char, int>mp;
        string ans ="";
        cout << "This is text1 map" << endl;
        for(int i = 0; i < text1.size(); i++)
        {
            if(mp[text1[i]] == 0)
                mp[text1[i]]++;
        }
        for(auto i:mp)
        {
            cout << i.first  << i.second << endl;
        }
        // return 0;
        cout << "This is text2 map" << endl;
        for(int j = 0; j < text2.size(); j++)
        {

            if(mp[text2[j]] == 1)
            {
                ans += text2[j];
                mp[text2[j]]--;
            }
        }
        cout << ans << endl;
        return 0;
    }
};
int main()
{
    Solution s;
    string s1 = "ezupkr";
    string s2 = "ubmrapg";
    s.longestCommonSubsequence(s1,s2);
}