// 374. Guess Number Higher or Lower
#include <bits/stdc++.h>
using namespace std;

// /**
//  * Forward declaration of guess API.
//  * @param  num   your guess
//  * @return 	     -1 if num is higher than the picked number
//  *			      1 if num is lower than the picked number
//  *               otherwise return 0
//  * int guess(int num);
//  */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long i = 1, ans = 0;
        while (i <= n)
        {
            long long guessNum = (i + n) / 2;
            // if(guess(guessNum) == 0){
            ans = guessNum;
            break;
            // else if(guess(guessNum) == -1)
            {
                n = guessNum - 1;
            }
            // else if(guess(guessNum) == 1)
            {
                i = guessNum + 1;
            }
        }
        return ans;
    }
};

int main()
{
}