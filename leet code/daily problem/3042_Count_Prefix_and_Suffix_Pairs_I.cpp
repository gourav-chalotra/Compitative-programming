#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int size = 0,sum = 0;
        for(int i = 0; i < words.size()-1; i++)
        {
            int currntMax = 0;
            for(int j = i+1; j < words.size(); j++)
            {
                if(words[i].size() > words[j].size())
                    continue;
                int iStart = 0,jStart = 0, iEnd = words[i].size()-1,jEnd = words[j].size()-1;
                // prefix
                bool notEqual = true;
                while(iStart < words[i].size() && iEnd >= 0 && jStart < words[j].size() && jEnd >= 0)
                {

                    if(words[i][iStart] != words[j][jStart])
                    {
                        notEqual = false;
                        break;
                    }
                    else if(words[i][iEnd] != words[j][jEnd])
                    {
                        notEqual = false;
                        break;
                    }
                    iStart++,iEnd--,jStart++,jEnd--;
                }
                if(notEqual)
                {
                    sum++;
                }
            }
        }
        return sum;
    }
};
int main()
{
    
}