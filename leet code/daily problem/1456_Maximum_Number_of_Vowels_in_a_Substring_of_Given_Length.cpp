#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Solution
{
public:
    int maxVowels(std::string s, int k)
    {
        std::queue<int> q1;
        int maxCount = 0, ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                maxCount++;
            q1.push(s[i]);
        }
        if(ans < maxCount)
        {
            ans = maxCount;
        }
        for (int j = k; j < s.size(); j++)
        {
            if (q1.front() == 'a' || q1.front() == 'e' || q1.front() == 'i'|| q1.front() == 'o' || q1.front() == 'u')
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                {
                    q1.pop();
                    q1.push(s[j]);
                }
                else
                {
                    maxCount--;
                    q1.pop();
                    q1.push(s[j]);
                }
            }
            else if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                maxCount++;
                q1.pop();
                q1.push(s[j]);
            }
            else
            {
                q1.pop();
                q1.push(s[j]);
            }
            if(ans < maxCount)
                ans = maxCount;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    std::string s1 = "weallloveyou";
    std::cout << s.maxVowels(s1, 7);
}