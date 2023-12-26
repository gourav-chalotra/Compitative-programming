#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        vector<char>::iterator i = upper_bound(letters.begin(),letters.end(),target);
        return (i==letters.end())?letters[0]:*i;
    }
};
int main()
{
    Solution s;
    vector<char>v = {'a','c','d','e'};
    cout << s.nextGreatestLetter(v,'a');
}