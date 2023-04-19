#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int cpyX = x;
        int revers = 0, digit = 1;
        while (cpyX)
        {
            int reminder = cpyX % 10;
            revers = revers * 10 + reminder;
            cpyX = (cpyX - reminder) / 10;
        }
        return ((int)(revers)-x == 0) ? true : false;
    }
};
int main()
{
    
    Solution s;
    cout << s.isPalindrome(123)<<endl;
    cout << s.isPalindrome(101)<<endl;
    cout << s.isPalindrome(100011)<<endl;
}