#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        unordered_map<int, char> mp = {{1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}};
        string ans = "";
        if(mp[num]){
            ans.push_back(mp[num]);
        }
        while (num>0)
        {
            if (num >= 1000)
            {
                ans.push_back('M');
                num -= 1000;
            }
            else if(num >= 900)
            {
                ans.push_back('C');
                ans.push_back('M');
                num -= 900;
            }
            else if (num >= 500)
            {
                ans.push_back('D');
                num -= 500;
            }
            else if(num >= 400)
            {
                ans.push_back('C');
                ans.push_back('M');
                num -= 400;
            }
            else if (num >= 100)
            {
                ans.push_back('C');
                num -= 100;
            }
            else if(num >= 90)
            {
                ans.push_back('X');
                ans.push_back('C');
                num -= 90;
            }
            else if (num >= 50)
            {
                ans.push_back('L');
                num -= 50;
            }
            else if(num >= 40)
            {
                ans.push_back('X');
                ans.push_back('L');
                num -= 40;

            }
            else if (num >= 10)
            {
                ans.push_back('X');
                num -= 10;
            }
            else if (num >= 9)
            {
                ans.push_back('I');
                ans.push_back('X');
                num -= 10;
            }
            else if (num >= 5)
            {
                ans.push_back('V');
                num -= 5;
            }
            else if(num >= 9)
            {
                ans.push_back('V');
                ans.push_back('I');
                num -= 9;
            }
            else if(num >= 4){
                ans.push_back('I');
                ans.push_back('V');
                num -= 4;
            }
            else if (num >= 1)
            {
                ans.push_back('I');
                num -= 1;
            }
            cout << "num: " << num << endl;
            cout << "ans: " << ans << endl;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(1994);
}