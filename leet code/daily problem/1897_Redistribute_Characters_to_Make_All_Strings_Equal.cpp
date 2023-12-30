#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                mp[words[i][j]]++;
            }
        }
        for(auto i: mp)
        {
            if((i.second % words.size()) != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string>word = {"caaaaa","aaaaaaaaa","a","bbb","bbbbbbbbb","bbb","cc","cccccccccccc","ccccccc","ccccccc","cc","cccc","c","cccccccc","c"};
    cout << s.makeEqual(word);
    return 0;
}