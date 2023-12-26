#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>mp;
        int i = 0,maxVal = 0,val = 0;
        while(i < arr.size()){
            mp[arr[i]]++;
            if(((float)mp[arr[i]]/arr.size())*100 > 25)
                val = arr[i];
            i++;
        }
        return val;
    }
};

int main()
{
    vector<int> v = {1,2,2,6,6,6,6,7,10};
    Solution s;
    cout << s.findSpecialInteger(v);
    return 0;
}