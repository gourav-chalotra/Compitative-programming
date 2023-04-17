// link:- https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/ 
#include<iostream>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result;
        for(int i = 0; i < candies.size();i++)
        {
            int maxCandies = candies[i]+extraCandies;
            int j = 0;
            for(; j < candies.size();j++)
            {
                if(j == i)
                {
                    continue;
                }
                if(maxCandies < candies[j])
                {
                    break;
                }
            }
            if(j == candies.size())
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};