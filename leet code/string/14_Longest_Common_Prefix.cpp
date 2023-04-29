#include<bits/stdc++.h>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int smallestStringLength = INT_MAX;
        for(int i = 0; i < strs.size(); i++)
            if(strs[i].size()<smallestStringLength)
                smallestStringLength = strs[i].size();
        std::string ans(strs[0].begin(),strs[0].end());
        
        for(int i = 0 ; i < strs.size(); i++)
        {
            std::string newString;
            for(int j = 0; j < smallestStringLength; j++)
            {
                if(strs[i][j] == ans[j])
                {
                    newString.push_back(ans[j]);
                }
                else
                {
                    break;
                }
            }
            ans = newString;
            smallestStringLength = ans.size();
        }
        return ans;
    }
};
int main()
{
    return 0;
}