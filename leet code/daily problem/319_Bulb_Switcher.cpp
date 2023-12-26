#include <iostream>
#include <math.h>
class Solution
{
public:
    int bulbSwitch(int n)
    {
        return std::sqrt(n);
    }
};
int main()
{
    Solution s;

    std::cout << s.bulbSwitch(6);
    return 0;
}