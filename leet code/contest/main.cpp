#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string majorityFrequencyGroup(string s)
    {
        unordered_map<char, int> charFreq;
        for (auto i : s)
        {
            charFreq[i]++;
        }
        unordered_map<int, vector<char>> freq;
        for (auto i : charFreq)
        {
            freq[i.second].push_back(i.first);
        }
        int maxSize = 0, key = -1;
        for (auto i : freq)
        {
            cout << "size of array: "<< i.second.size() << endl;
            cout << endl;
            if (i.second.size() > maxSize || (i.second.size() == maxSize && i.first > key))
            {
                maxSize = i.second.size();
                key = i.first;
            }
            else if (i.second.size() == maxSize)
            {
                if (i.first > key)
                {
                    key = i.first;
                }
            }
            cout << "key: "<< key << endl;
        }
        if(key == -1)
        {
            return "";
        }
        string ans;
        cout << "Key value: " << key << endl;
        for (int i = 0; i < freq[key].size(); i++)
        {
            cout << freq[key][i] << " ";
        }
        return ans;
    }
};
int main()
{
    string str = "pfpfgi";
    Solution s;
    cout << s.majorityFrequencyGroup(str);
}