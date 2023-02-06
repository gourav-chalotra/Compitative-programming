// Mario was going to gift Princess Peach a string SS of even length NN.
// Mario was clumsy and thus, broke the string in the middle. He now has two strings AA and BB such that A = S[1, \frac{N}{2}]A=S[1,2N​] and B = S[\frac{N}{2} + 1, N]B=S[2N​+1,N].
// Mario is not sure about the order in which he should join the strings AA and BB to get the string SS. Thus, he joins the strings in any random order. Find whether it is guaranteed that Mario will get the same string SS if he joins the strings AA and BB in any order.
// Note that S[L, R]S[L,R] denotes a substring of string SS starting at index LL and having a length (R - L + 1)(R−L+1).
#include <iostream>
using namespace std;

int main()
{
    string name;
    cin >> name;
    int N = name.size(), check = 0, l = 0;

    char A[N / 2], B[N / 2];
    for (int i = 0; i < N; i++)
    {
        if (i < N / 2)
        {
            A[i] = name[i];
        }
        else
        {
            B[l] = name[i];
            l++;
        }
    }

    for (int i = 0; i < N / 2; i++)
    {
        if (A[i] != B[i])
        {
            check = 1;
        }
    }
    if (check)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}