#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() <= 2)
        {
            return fruits.size();
        }
        int NumberOfFruits = 1, basket1 = 0, basket2 = -1,maxFruits = INT_MIN;
        for(int i = 1; i < fruits.size(); i++)
        {
            if (fruits[basket1] == fruits[i])
            {
                NumberOfFruits++;
            }
            else if(basket2 == -1)
            {
                NumberOfFruits++;
                basket2 = i;
            }
             else if (fruits[basket2] == fruits[i])
            {
                NumberOfFruits++;
            }
            else
            {
                if(NumberOfFruits >= maxFruits)
                {
                    maxFruits = NumberOfFruits;
                }
                NumberOfFruits = 1;
                    basket1 = basket2;
                    i = basket1;
                    basket2 = -1;
            }
        }
        if(NumberOfFruits > maxFruits)
        {
            maxFruits = NumberOfFruits;
        }
        return maxFruits;
    }
};

int main()
{
	Solution s;
	vector<int> fruits = {3, 3, 3, 1, 4};
	cout << s.totalFruit(fruits);
	return 0;
}
