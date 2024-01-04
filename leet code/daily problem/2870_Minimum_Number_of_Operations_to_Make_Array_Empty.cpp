#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>ht;
        int i = 0,op = 0;
        while(i < nums.size())
        {
            ht[nums[i]]++;
            i++;
        }
        unordered_map<int,int>::iterator it = ht.begin();
        for(;it!=ht.end(); it++)
        {
            if(it->second == 1)
            {
                return -1;
            }
            op += (it->second/3)+((it->second%3 + 1)/2);
        }
        return op;
    }
};
int main()
{
    return 0;
}