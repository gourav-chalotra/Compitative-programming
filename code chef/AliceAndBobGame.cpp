#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int check = 0;
        int n, j = 0; // length of a string
        cin >> n;
        char s[n], A[n / 2 + 1], B[n / 2]; // string
        // done
        for (int j = 0; j < n; j++)
        {
            cin >> s[j];
        }
        // done
        for (char x : s)
        {
            cout << "The value of x is: " << x << endl;
        }
        // done 
        for (int k = 0, fB = 0, Ac = 0; k < n; k++)
        {
            if (k % 2)
            {
                B[fB] = s[k];
                cout << "The value of B[fB] is: " << B[fB] << endl;
                fB++;
            }
            else
            {
                A[Ac] = s[k];
                cout << "The value of A[Ac] is: " << A[Ac] << endl;
                Ac++;
            }
        }
        
        
    }

    return 0;
}
