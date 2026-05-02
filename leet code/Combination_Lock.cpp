#include<bits/stdc++.h>
using namespace std;
int uppOrdow(int num, int targetNum)
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int countOne = 0,countTwo = 0;
    for(int i = num; i != targetNum; i++)
    {
        if(i > 9){
            i = 0;
        }
        countOne++;
    }
    for(int i = num; i != targetNum; i--)
    {
        if(i < 0){
            i = 9;
        }
        countTwo++;
    }
    return min(countOne,countTwo);
}
int main(){
    int n;
    cout << "Enter: "<< endl;
    cin >> n;
    vector<int>defaultDick(n,0);
    for(int i = 0; i < defaultDick.size(); i++)
    {
        cin >> defaultDick[i];
    }
    vector<int>resultDick(n,0);
    for(int i = 0; i < resultDick.size(); i++)
    {
        cin >> resultDick[i];
    }
    int result = 0;
    for(int i = 0; i < defaultDick.size(); i++)
    {
        result += uppOrdow(defaultDick[i],resultDick[i]);
    }
    cout << "result: "<< result << endl;


}