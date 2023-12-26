#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool Duplicate(vector<int> arr, int length)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i <= length; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                return true;
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int NumberOfElementFilledInBoard = 0;
        // Displaying board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
                if (board[i][j] != '.')
                {
                    NumberOfElementFilledInBoard++;
                }
            }
            cout << endl;
        }
        // if Number of element == 0 ?
        if (NumberOfElementFilledInBoard == 0)
        {
            return true;
        }
        else
        {
            NumberOfElementFilledInBoard = 0;
            // Rows
            for (int i = 0; i < 9; i++)
            {
                vector<int> row(10, 10);
                int rowLength = -1;
                vector<int> coloum(10, 10);
                int coloumLength = -1;

                // coloums
                for (int j = 0; j < 9; j++)
                {
                    // Rows
                    if (board[i][j] != '.')
                    {
                        row[board[i][j] - 48] = board[i][j] - 48;
                        NumberOfElementFilledInBoard++;
                        rowLength++;
                    }
                    // Coloums
                    if (board[j][i] != '.')
                    {
                        coloum[board[j][i] - 48] = board[j][i] - 48;
                        NumberOfElementFilledInBoard++;
                        coloumLength++;
                    }
                }
                // Displaying rows and coloums of the matrix
                cout << "\nRows" << endl;
                for (auto i : row)
                {
                    if (i != 10)
                    {
                        cout << i << " ";
                    }
                }
                cout << "\n"
                     << endl;
                cout << "Coloums" << endl;
                for (auto i : coloum)
                {
                    if (i != 10)
                    {
                        cout << i << " ";
                    }
                }
                cout << endl;

                if (Duplicate(row, rowLength))
                {
                    return false;
                }
                if (Duplicate(coloum, coloumLength))
                {
                    return false;
                }
            }
        }
        for (int m = 0; m < 9; m += 3)
        {
            for (int n = 0; n < 9; n += 3)
            {
                int i = m, lengthOfSquareElement = -1;
                vector<int> square3x3(10, 10);
                for (; i < (m + 3); i++)
                {
                    for (int j = n; j < (n + 3); j++)
                    {
                        if (board[i][j] != '.' && square3x3[board[i][j] - 48] == 10)
                        {

                            square3x3[board[i][j] - 48] = board[i][j] - 48;
                            lengthOfSquareElement++;
                        }
                        else if (board[i][j] != '.' && square3x3[board[i][j] - 48] != 10)
                        {
                            return false;
                        }
                    }
                    cout << endl;
                }
                sort(square3x3.begin(), square3x3.end());
                if(Duplicate(square3x3, lengthOfSquareElement))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> a = {{'.', '.', '.', '.', '.', '.', '.', '.', '2'}, {'.', '.', '.', '.', '.', '.', '6', '.', '.'}, {'.', '.', '1', '4', '.', '.', '8', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '3', '.', '.', '.', '.'}, {'5', '.', '8', '6', '.', '.', '.', '.', '.'}, {'.', '9', '.', '.', '.', '.', '4', '.', '.'}, {'.', '.', '.', '.', '5', '.', '.', '.', '.'}};
    ;
    cout << s.isValidSudoku(a);
}
