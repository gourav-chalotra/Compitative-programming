#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        // Monotonic stack
        stack<int>monoStkMin;
        vector<int>nOfSeenPeople(h.size(), 0);
        for(int i = h.size()-1; i >= 0; i--)
        {
            if(monoStkMin.empty())
            {
                monoStkMin.push(h[i]);
            }
            else
            {
                if(h[i] > monoStkMin.top()){
                    int countPoeple = 0;
                    while( !monoStkMin.empty() && monoStkMin.top() < h[i] )
                    {
                        countPoeple++;
                        monoStkMin.pop();
                    }
                    if(monoStkMin.empty()){
                        nOfSeenPeople[i] = countPoeple;
                    }
                    else if(!monoStkMin.empty()){
                        nOfSeenPeople[i] = countPoeple+1;
                    }
                    monoStkMin.push(h[i]);
                }
                else
                {
                    nOfSeenPeople[i] = 1;
                    monoStkMin.push(h[i]);
                }
            }
        }
        return nOfSeenPeople;
    }
};
int main()
{
    Solution s;
    vector<int> h = {10, 6, 8, 5, 11, 9};
    vector<int> ans = s.canSeePersonsCount(h);
    cout << "Number of people can seen: "<< endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}