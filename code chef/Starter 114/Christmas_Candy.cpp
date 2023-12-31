#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,count = 0;
	    cin >> n;
	    vector<int>arr(n+1,0);
	    for(int i = 1; i <= n ;i++)
	    {
	        int num;
	        cin >> num;
	        arr[num] = i;
	    }
	    for(int i = 1; i < n; i++)
	    {
	        vector<int>s(arr.begin()+i+1,arr.end());
	        sort(s.begin(),s.end());
            cout << "s values "<<endl;
            for(auto i : s)
                cout << i << endl;
	        if(s[s.size()-1] < arr[i]){
	            count++;
	        }
	    }
	    cout << count << endl;
	}
}
