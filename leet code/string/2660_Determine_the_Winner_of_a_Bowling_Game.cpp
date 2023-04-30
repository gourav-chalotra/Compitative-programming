#include<iostream>
#include<vector>
class Solution {
public:
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) {
        int sumP1 = player1[0], sumP2 = player2[0];
        for(int i = 1; i < player1.size(); i++)
        {
            if(i == 1)
            {
                if(player1[i-1] == 10)
                {
                    sumP1 += player1[i]*2;
                }
                else
                {
                    sumP1 += player1[i];
                }
                if(player2[i-1] == 10)
                {
                    sumP2 += player2[i]*2;
                }
                else
                {
                    sumP2 += player2[i];
                }
            }
            else 
            {
                if(player1[i-1] == 10  || player1[i-2] == 10)
                {
                    sumP1 += player1[i]*2;
                }
                else
                {
                    sumP1 += player1[i];
                }
                if(player2[i-1] == 10  || player2[i-2] == 10)
                {
                    sumP2 += player2[i]*2;
                }
                else
                {
                    sumP2 += player2[i];
                }
            }
        }
        std::cout <<"sumP1: "<< sumP1 <<" "<<"sumP2: "<< sumP2 << std::endl;
        return (sumP1>sumP2)?1:(sumP1==sumP2)?0:2;
    }
};
int main()
{
    return 0;
}