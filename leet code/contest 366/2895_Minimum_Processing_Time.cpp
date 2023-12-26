#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        // step 1 sort the arrays
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        vector<int> ansMaxTask;
        int last = tasks.size() - 1;
        for (int i = 0; i < processorTime.size(); i++)
        {
            int maxTask = 0;
            int l = last - 4;
            for (; last > l && last >= 0; last--)
            {
                if(maxTask < processorTime[i]+tasks[last])
                    maxTask = processorTime[i]+tasks[last];
            }
            // cout << maxTask << endl;
            ansMaxTask.push_back(maxTask);
        }
        int ans = 0;
        for(int i = 0; i < ansMaxTask.size(); i++)
        {
            ans = max(ans,ansMaxTask[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int>processorTime = {10,20};
    vector<int>tasks = {2,3,1,2,5,8,4,3};
    Solution s;
    cout << s.minProcessingTime(processorTime,tasks);
    return 0;
}