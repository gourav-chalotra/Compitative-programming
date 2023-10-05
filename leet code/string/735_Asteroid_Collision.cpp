#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        int i = 0;
        while (i < asteroids.size())
        {
            if (stk.empty())
            {
                stk.push(asteroids[i]);
                i++;
            }
            else if (stk.top() + asteroids[i] > 0)
            {
                if (stk.top() > 0 && asteroids[i] < 0)
                {
                    i++;
                    continue;
                }
                // if both astroides have same direction
                else if (stk.top() > 0 && asteroids[i] > 0)
                {
                    stk.push(asteroids[i]);
                    i++;
                }
                else if (stk.top() < 0 && asteroids[i] > 0)
                {
                    stk.push(asteroids[i]);
                    i++;
                    continue;
                }
            }
            else if (stk.top() + asteroids[i] < 0)
            {
                if (stk.top() > 0 && asteroids[i] < 0)
                {

                    if (stk.top() > 0)
                    {
                        stk.pop();
                    }
                    else if (stk.top() + asteroids[i] > 0 && stk.top() > 0)
                    {
                        i++;
                    }
                }
                // if both astroides have same direction
                else if (stk.top() < 0 && asteroids[i] < 0)
                {
                    stk.push(asteroids[i]);
                    i++;
                    continue;
                }
                else if (stk.top() < 0 && asteroids[i] > 0)
                {
                    stk.push(asteroids[i]);
                    i++;
                    continue;
                }
            }
            else if (stk.top() + asteroids[i] == 0 && (stk.top() > 0 && asteroids[i] < 0))
            {
                stk.pop();
                i++;
            }
            else
            {
                stk.push(asteroids[i]);
                i++;
            }
        }
        vector<int> a;
        while (!stk.empty())
        {
            a.push_back(stk.top());
            stk.pop();
        }
        reverse(a.begin(), a.end());
        return a;
    }
};
int main()
{
    vector<int> val = {-2, -2, -1, 2};
    Solution s;
    vector<int> ans = s.asteroidCollision(val);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}