#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
class Solution
{
public:
    int numRescueBoats(std::vector<int> &ppl, int limit, int boats = 0)
    {
        std::sort(begin(ppl), end(ppl));
        for (int i = 0, j = ppl.size() - 1; i <= j; ++boats, --j)
        {
            if (ppl[i] + ppl[j] <= limit)
                ++i;
        }
        return boats;
    }
};

int main()
{
    std::vector<int> people = {3, 2, 2, 1};
    Solution s;
    std::cout << s.numRescueBoats(people,3); 
    return 0;
}