#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>s1;
        sort(arr.begin(), arr.end());
        int count = 1,differentN = 1, val = arr[0];
        for(int i = 1;i<arr.size(); i++)
        {
            if(val != arr[i])
            {
                s1.insert(count);
                count = 1;
                differentN++;
                val = arr[i];
            }
            else
                count++;
        } 
        s1.insert(count);
        if(s1.size() == differentN)
            return true;
        return false;
    }
};

int main()
{
    return 0;
}