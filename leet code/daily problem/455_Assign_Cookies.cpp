#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int count = 0;
        for(int j = 0, i = 0; j < s.size(); j++)
        {
            for(;i < g.size(); i++)
            {
                if(s[j] >= g[i]){
                    count++,i++;
                    break;
                }
                break;
            }
        }
        return count;
    }
};
int main()
{
    vector<int> g = {1,2}, s = {1,2,3};

    Solution c;
    cout << c.findContentChildren(g, s);
}