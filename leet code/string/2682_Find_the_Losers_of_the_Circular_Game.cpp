#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    std::vector<int> circularGameLosers(int n, int k)
    {
        std::vector<int> check(n + 1, 0), ans;
        int i = 1, steps = 1;
        while (true && check[i] != 2)
        {
            check[i]++;
            if(check[i]==2)
            {
                break;
            }
            i += (steps * k);
            i%=n;
            steps++;
        }
        i = 1;
        while (i < check.size())
        {
            if (check[i] == 0)
            {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    std::vector<int> ans = s.circularGameLosers(4,4);
    for(auto i : ans)
    {
        std::cout << i << " ";
    }

}