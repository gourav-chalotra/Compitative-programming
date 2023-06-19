#include <iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        stack<int> s;
        s.push(0);
        int max = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            s.push(gain[i] + s.top());
            if (max < s.top())
                max = s.top();
        }
        return max;
    }
};
