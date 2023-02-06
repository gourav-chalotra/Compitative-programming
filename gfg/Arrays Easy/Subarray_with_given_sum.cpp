// N = 10, S = 15
// A[] = {1,2,3,4,5,6,7,8,9,10}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int n = 5;
    long long s = 12;

    vector<int> v1;
    v1.push_back(-1);
    int subSum, check = 0;
    for (int i = 0; i < n - 1; i++)
    {
        subSum = arr[i];
        for (int j = i + 1; subSum < s; j++)
        {
            subSum = subSum + arr[j];
            if (subSum == s)
            {
                cout << "arr[i] : " << arr[i] << " arr[j] : " << arr[j] << endl;
                cout << "i: "<<i<<" j: "<< j << endl;
                cout << subSum << endl;
                v1.pop_back();
                v1.push_back(i + 1);
                v1.push_back(j + 1);
                check = 1;
                break;
            }
            j++;
        }
        if (check)
        {
            break;
        }
    }
    int i = 0;
    while (i < v1.size())
    {
        cout << v1[i] << " ";
        i++;
    }

    return 0;
}