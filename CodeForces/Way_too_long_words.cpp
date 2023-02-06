#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string world;
        cin >> world;
        int count = 0;
        while (world[count] != '\0')
        {
            count++;
        }
        if (count > 10)
        {
            cout << count << endl;
            cout << world[0] << count - 2 << world[count - 1] << endl;
        }
        else
        {
            cout << world << endl;
        }
    }

    return 0;
}