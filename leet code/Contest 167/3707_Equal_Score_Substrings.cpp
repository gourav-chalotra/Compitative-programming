#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool scoreBalance(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            total += ((s[i] - 'a') + 1);
        }
        int currentSum = 0;
        for (int i = 0; i < s.size(); i++) {
            currentSum += ((s[i] - 'a') + 1);
            if (total - currentSum == currentSum) {
                return true;
            }
        }
        return false;
    }
};

int main()
{

}