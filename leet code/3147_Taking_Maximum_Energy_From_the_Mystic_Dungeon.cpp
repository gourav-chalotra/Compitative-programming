#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathFind(vector<int>&energy, int k, int index, int& MaxEnergy)
    {
        if(index >= energy.size())
        {
            cout << "maxEnery: "<< MaxEnergy << endl;
            return MaxEnergy;
        }
        cout << "index: " << energy[index] << endl;
        MaxEnergy += energy[index];
        cout << MaxEnergy << endl;
        pathFind(energy, k, index+k, MaxEnergy);
        return MaxEnergy;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxValue = energy[0];
        for(int i = 0; i < energy.size(); i++)
        {
            int currentMax = 0;
            currentMax = pathFind(energy, k,i, currentMax);
            cout << "\n\n\ncurrentMax: "<< currentMax << endl;
            cout << "\n\n\n\n\n"<< endl; 
            maxValue = max(currentMax, maxValue);
        }
        return maxValue;
    }
};

int main()
{
    Solution s;
    vector<int>energy = {5,2,-10,-5,1};
    int k = 3;
    cout << s.maximumEnergy(energy, k);
}