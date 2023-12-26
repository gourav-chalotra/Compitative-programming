#include<iostream>
class Solution {
public:
    int addDigits(int num) 
    {
        int digitSum = 0;
        while(num || digitSum > 9)
        {
            if(num == 0 && digitSum>9){
                num = digitSum;
                digitSum = 0;
            }
                
            digitSum = digitSum + (num%10);
            num/=10;
            
        }
        return digitSum;
    }
};
int main()
{
    // tast case
    Solution s;
    std::cout << s.addDigits(38);
}