// Problem : https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        vector<int>digitsCount(10,0);
        for(auto i : digits)
            digitsCount[i]++;

        for(int num = 100; num < 999; num+=2)
        {
            vector<int>currentNumFreq(10,0);

            int temp = num;
            while(temp)
            {
                currentNumFreq[(temp%10)]++;
                temp/=10;
            }
            bool flag = true;
            for(int i = 0; i < 10; i++)
            {
                if(currentNumFreq[i] > digitsCount[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main()
{
    
}