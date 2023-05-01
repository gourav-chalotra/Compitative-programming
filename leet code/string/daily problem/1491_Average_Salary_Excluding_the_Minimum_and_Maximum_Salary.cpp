#include <iostream>
#include<algorithm>
#include <vector>
class Solution {
public:
    double average(std::vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double sumE = 0;
        for(int i = 1; i < salary.size()-1; i++)
            sumE+=salary[i];
        return sumE/=salary.size()-2;
    }
};
int main()
{
    Solution s;
    std::vector<int>a = {1000,2000,3000};
    std::cout << s.average(a);
}