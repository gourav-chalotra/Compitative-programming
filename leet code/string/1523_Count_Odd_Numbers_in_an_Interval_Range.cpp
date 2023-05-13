#include <iostream>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
            if (i % 2)
                count++;

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countOdds(3,7);
}