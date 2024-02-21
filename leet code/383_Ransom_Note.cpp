// 383. Ransom Note
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(int i = 0; i < ransomNote.size(); i++)
            mp[ransomNote[i]]++;
        for(int i = 0; i < magazine.size(); i++)
            mp[magazine[i]]--;
        
        for(int i = 0; i < ransomNote.size(); i++)
            if(mp[ransomNote[i]] >= 1)
                return false;
        return true;
    }
};
int main()
{
    
}