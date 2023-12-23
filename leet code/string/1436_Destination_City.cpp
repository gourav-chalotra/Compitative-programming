// Question link:- https://leetcode.com/problems/destination-city/
// My Leetcode Solution Link:- https://leetcode.com/problems/destination-city/solutions/4444154/using-map/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
       unordered_map<string, string> ump;

       for(auto &it: paths) {
           ump[it[0]] = it[1];
       }

       for (auto &it: ump) {
           if (ump.find(it.second) == ump.end()) {
               return it.second;
           }
       }

       return "";
    }
};
int main()
{
    return 0;
}