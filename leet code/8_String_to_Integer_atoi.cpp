#include <iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        s = s.substr(i);
        int sign = 1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1,i++;
        else if(s[0] == '+') i++;
        int MAX = INT32_MAX,MIN = INT32_MIN;
        i = 0;
        while(i < s.size())
        {
            if(s[i] == ' ' || !isdigit(s[i])) break;    
            ans = ans*10+s[i]-'0';
            if(sign == -1 && ans*-1 < MIN)
                return MIN;
            if(sign == 1 && ans > MAX)
                return MAX;
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    string findNumber = "20000000000000000000";
    cout << s.myAtoi(findNumber);
}