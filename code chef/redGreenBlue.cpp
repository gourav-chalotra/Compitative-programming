#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int minNumber;
	for (int i = 0; i < T; i++)
	{
		minNumber = 0;
		int N, K, j;
		cin >> N >> K;
		int arr[N];
		for (j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		for (j = 0; j < N; j++)
		{
			if (arr[j] > K)
			{
				minNumber++;
			}
		}
		cout << minNumber << endl;
	}

	return 0;
}
