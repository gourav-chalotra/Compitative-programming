#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int negitive = (x>=0)?0:1;
        int cpy = x,val = 0,digit,place = 10;
        while(cpy)
        {
            cout << cpy << endl;
            digit = cpy%10;
            val=digit+(val*place);
            if(val > pow(2,31)-1)
            {
                val = val-pow(2,31)-1;
            }
            cout << val << endl;
            cpy/=10;
        }
        cout << val << endl;
        return val;
    }
};