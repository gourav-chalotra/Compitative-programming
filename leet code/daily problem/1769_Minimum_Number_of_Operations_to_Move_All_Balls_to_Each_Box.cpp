#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i = 0; i < boxes.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < boxes.size(); j++)
            {
                if(j==i)
                    continue;
                else if(boxes[j] == '1')
                {
                    int minDistance = j-i;
                    sum += (minDistance < 0)?(-(minDistance)):minDistance;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string boxes = "110";
    vector<int> result = s.minOperations(boxes);
    for(int i : result)
        cout<<i<<" ";
    return 0;
}