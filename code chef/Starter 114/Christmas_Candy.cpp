#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    int curMax = arr[0],countCandy = 0;
	    for(int i = 1; i < n; i++)
	    {
	        if(curMax < arr[i])
	        {
	            curMax = arr[i];
	        }
	        else
	            countCandy++;
	    }
	    cout << countCandy << endl;
	}
}
