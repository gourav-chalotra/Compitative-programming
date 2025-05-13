// Problem : https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13


// good question (Medium)

// Brute force (Memory Limit Exceeded)
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        while(t--)
        {
            string str = "";
            for(auto i : s)
            {
                if(i == 'z')
                {
                    str = str+"ab";
                }
                else
                {
                    char nextChar = i+1;
                    str = str + nextChar;
                }
                
            }
            s = str;
        }
        return s.size();
    }
};
// TLE solution 
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        unordered_map<char, long long> mp;

        for (char c : s) {
            mp[c]++;
        }

        while (t--) {
            unordered_map<char, long long> newMap;
            for (auto &i : mp) {
                if (i.first == 'z') {
                    newMap['a'] = (newMap['a'] + i.second) % MOD;
                    newMap['b'] = (newMap['b'] + i.second) % MOD;
                } else {
                    char nextChar = i.first + 1;
                    newMap[nextChar] = (newMap[nextChar] + i.second) % MOD;
                }
            }
            mp = newMap;
        }

        long long totalLength = 0;
        for (auto &i : mp) {
            totalLength = (totalLength + i.second) % MOD;
        }

        return totalLength;
    }
};

// Better Submition accepted 
// Time complexity O(N+T)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        const int MOD = 1e9 + 7;
        vector<long long> counts(26, 0);

        for (char c : s)
        {
            counts[c - 'a']++;
        }

        while (t--)
        {
            vector<long long> newCounts(26, 0);
            for (int i = 0; i < 26; ++i)
            {
                if (counts[i] == 0)
                    continue;

                if (i == 25)
                {
                    newCounts[0] = (newCounts[0] + counts[i]) % MOD;
                    newCounts[1] = (newCounts[1] + counts[i]) % MOD;
                }
                else
                {
                    newCounts[i + 1] = (newCounts[i + 1] + counts[i]) % MOD;
                }
            }
            counts = newCounts;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i)
        {
            result = (result + counts[i]) % MOD;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string str = "abcyy";
    cout << s.lengthAfterTransformations(str, 3);
}