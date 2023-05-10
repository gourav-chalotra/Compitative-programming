#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        std::vector<std::vector<int>>v1(n,std::vector<int>(n,0));
        int count = 1;
        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                v1[rowStart][j] = count++;
            }
            rowStart++;
            for (int i = rowStart; i <= rowEnd && rowStart <= rowEnd && colStart <= colEnd; i++)
            {
                v1[i][colEnd] = count++;
            }
            colEnd--;
            for (int j = colEnd; j >= colStart && rowStart <= rowEnd && colStart <= colEnd; j--)
            {
                v1[rowEnd][j] = count++;
            }
            rowEnd--;
            for (int i = rowEnd; i >= rowStart && rowStart <= rowEnd && colStart <= colEnd; i--)
            {
                v1[i][colStart] = count++;
            }
            colStart++;
        }
        return v1;
    }
    
};
int main()
{
    Solution s;
    std::vector<std::vector<int>> v1 = s.generateMatrix(3);
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            std::cout << v1[i][j] << " ";
        }
    }
}