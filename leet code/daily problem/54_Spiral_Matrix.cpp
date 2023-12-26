#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[rowStart].size() - 1;
        std::vector<int> ans;
        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                ans.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            for (int i = rowStart; i <= rowEnd && rowStart <= rowEnd && colStart <= colEnd; i++)
            {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            for (int j = colEnd; j >= colStart && rowStart <= rowEnd && colStart <= colEnd; j--)
            {
                ans.push_back(matrix[rowEnd][j]);
            }
            rowEnd--;
            for (int i = rowEnd; i >= rowStart && rowStart <= rowEnd && colStart <= colEnd; i--)
            {
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        return ans;
    }
};
int main()
{
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    std::vector<int> ans = s.spiralOrder(matrix);
    for (auto i : ans)
        std::cout << i << " ";
}