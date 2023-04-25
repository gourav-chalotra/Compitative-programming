#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findChar(vector<char> v1, char c)
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] == c)
            {
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s)
    {
        int maxSubArrCount = 0;
        vector<char> v1;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (!findChar(v1, s[j]))
                {
                    v1.push_back(s[j]);
                }
                else
                {
                    if (maxSubArrCount < v1.size())
                    {
                        maxSubArrCount = v1.size();
                    }
                    v1.clear();
                    break;
                }
            }
        }
        if (maxSubArrCount < v1.size())
        {
            maxSubArrCount = v1.size();
        }
        return maxSubArrCount;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
