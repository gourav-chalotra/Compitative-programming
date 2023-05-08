#include <iostream>
#include <vector>
class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) 
    {
        int Psum = 0, Ssum = 0;
        for(int i = 0; i < mat.size();i++)
        {
            if(i!=mat.size()-1-i)
                Ssum+=mat[i][mat.size()-1-i];
            Psum+=mat[i][i];
        }
        return Psum+Ssum;
    }
};
int main()
{
    Solution s;
    std::vector<std::vector<int>> mat = {{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};
    std::cout << s.diagonalSum(mat);
}