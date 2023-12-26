#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1, h, b, container, maxContainer = INT_MIN;
        for(; i < j ;)
        {
            h = (height[i] >= height[j])?height[j]:height[i];
            b = j - i;
            container = h*b;
            if(maxContainer < container)
                maxContainer = container;
            (height[i] >= height[j])?j--:i++;
        }
        return maxContainer;
    }
};
int main()
{
    return 0;
}