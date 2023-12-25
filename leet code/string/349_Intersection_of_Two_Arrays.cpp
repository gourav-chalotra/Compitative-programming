#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        set<int>s2;
        int i;
        int arr[1001] = {0};
        vector<int>ans;
        for( i = 0; i < nums1.size(); i++)
            s1.insert(nums1[i]);
        for( i = 0; i < nums2.size(); i++)
            s2.insert(nums2[i]);

        set<int>::iterator it = s1.begin();
        for(;it != s1.end(); it++)
            arr[*it]++;
        for(it = s2.begin();it != s2.end(); it++){
            arr[*it]++;
            if(arr[*it] == 2)
                ans.push_back(*it);
        }
        return ans;
    }
};
using namespace std;
int main()
{

}