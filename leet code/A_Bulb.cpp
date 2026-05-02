#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int,int>find;
    for(int i = 0; i < n; i++)
    {
        int x,num;
        cin >> x;
        for(int j = 0; j < x; j++)
        {
            cin >> num;
            find[num] = 1;
        }
    }
    cout << (m == find.size())?"YES":"NO";
}