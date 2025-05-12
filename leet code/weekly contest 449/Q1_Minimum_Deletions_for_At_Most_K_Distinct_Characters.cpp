// Problem : https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>fq;
        int opt = 0;
        for(int i = 0; i < s.size(); i++)
            {
                fq[s[i]]++;
            }
        while(fq.size() > k)
        {
            int minNum = INT_MAX;
            char minChar = ' ';
            for(auto i : fq)
            {
                if(i.second < minNum)
                {
                    minNum = i.second;
                    minChar = i.first;
                }
            }
            opt += minNum;
            fq.erase(minChar);
        }
        return opt;
    }
};
int main(){
    
}