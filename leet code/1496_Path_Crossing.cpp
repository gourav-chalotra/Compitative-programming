// Question link :- https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2023-12-23
// My Solution :- https://leetcode.com/problems/path-crossing/solutions/4443961/100-beats-set/?envType=daily-question&envId=2023-12-23
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> x = {{0,0}},y = {{0,0}};
        int i = 0,x1 = 0,y1 = 0;
        while(i < path.size())
        {
            if(path[i] == 'N')
                y1++;
            else if(path[i] == 'S') 
                y1--;
            else if(path[i] == 'E')
                x1--;
            else if(path[i] == 'W')
                x1++;
            if((x.find({x1,y1}) != x.end()) && (y.find({x1,y1}) != y.end()))
            {
                return true;
            }
            x.insert({x1,y1});
            y.insert({x1,y1});
            i++;
        }
        return false;
    }
};
int main()
{
    Solution s;
    cout << s.isPathCrossing("NES");
    return 0;
}