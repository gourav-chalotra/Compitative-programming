#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s) {
    int n = s.size(), maxSize = 1;
    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++) {
            freq[s[j]-'a']++;
            int val = 0;
            bool valid = true;
            for (int f : freq) {
                if (f != 0) {
                    if (val == 0) val = f;
                    else if (val != f) valid = false;
                }
            }
            if (valid) maxSize = max(maxSize, j-i+1);
        }
    }
    return maxSize;
}
};

