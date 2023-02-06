#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
	    int x,y;
	    cin >> x >> y;
	    int n = 1;
	    for(n; n <= 1e+18; n++)
	    {
	        if(((n+y)%x == 0) && ((n+x)%y == 0))
	        {
	            cout << n << endl;
	            break;
	        }
	    }
	}
	return 0;
}