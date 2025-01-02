#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<char,int>vowel;
        vowel['a'] = 1;
        vowel['e'] = 1;
        vowel['i'] = 1;
        vowel['o'] = 1;
        vowel['u'] = 1;
        vector<int>countValid,ans;
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(vowel[words[i][0]] && vowel[words[i][words[i].size()-1]])
            {
                count++;
            }
            countValid.push_back(count);
        }
        for(int i = 0; i < queries.size(); i++)
        {
            int maxSize = countValid[queries[i][1]];
            if(queries[i][0] > 0)
            {
                maxSize = maxSize - countValid[queries[i][0]-1];
            }
            ans.push_back(maxSize);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string>words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    s.vowelStrings(words,queries);
    vector<int>ans = s.vowelStrings(words,queries);
    for(auto i : ans)
    {
        cout << i << endl;
    }

}