#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestNumber(int n) {
        int i = n;
        while(i)
        {
            int cpi = i;
            int countLength = 0,oneLength = 0;
            while(cpi)
            {
                if((cpi & 1))
                {
                    oneLength++;
                }
                
                countLength++;
                cpi = cpi >> 1;
            }
            cout << oneLength << " " << countLength << endl;
            if(oneLength == countLength) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    cout << s.smallestNumber(3);
}