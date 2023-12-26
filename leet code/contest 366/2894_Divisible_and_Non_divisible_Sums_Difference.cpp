#include<iostream>
using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int i = 1;
        int num1Sum = 0,num2Sum = 0;
        while(i <= n)
        {
            if(i%m != 0)
                num1Sum += i;
            else if(i%m == 0)
                num2Sum += i;
            i++;
        }
        return num1Sum-num2Sum;
    }
};
int main()
{
    Solution s;
    cout << s.differenceOfSums(10,3);
}