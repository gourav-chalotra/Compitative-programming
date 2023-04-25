#include <iostream>
#include <vector>
class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if(numRows==1)
        {
            return s;
        }
        std::vector<std::vector<char>> ans(numRows, std::vector<char>(s.size(), '0'));
        int r = 0, colum = 0, i = 0;
        while (i < s.size())
        {
            for (; r < numRows && i < s.size(); r++)
            {
                ans[r][colum] = (i < s.size()) ? s[i] : '0';
                i++;
            }
            r -= 2, colum++;
            for (; r > 0 && i < s.size(); r--)
            {
                ans[r][colum] = (i < s.size()) ? s[i] : '0';
                colum++;
                i++;
            }
        }
        i = 0, colum = 0;
        std::string ValidString;
        for (; i < ans.size(); i++)
        {
            for (colum = 0; colum < ans[i].size(); colum++)
            {
                if (ans[i][colum] != '0')
                    ValidString.push_back(ans[i][colum]);
            }
        }
        return ValidString;
    }
};
int main()
{
    Solution s;
    std::string s1 = "paypalishiring";
    std::cout << s.convert(s1, 3);
    return 0;
}