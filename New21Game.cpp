// New21Game.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int N, W, K;
	cin >> N >> K >> W;
	int* arr = new int[K + W];
	arr[0] = 0;
	if (K < W)
	{
		for (int i = 1; i < K; i++)
		{
			arr[i] = pow(2, i - 1);
			
		}
		for (int i = K; i <= W; i++)
		{
			arr[i] = 1;
			for (int j = 1; i - j && j <= W && i - j < K; j++)
				arr[i] += arr[i - j];
		}
		for (int i = W+1; i < W+K; i++)
		{
			arr[i] = 0;
			for (int j = 1; j <= W && i - j < K; j++)
				arr[i] += arr[i - j];
		}
	}
	else
		for (int i = 1; i < K + W; i++)
		{
			if (i <= W)
				arr[i] = pow(2, i - 1);
			else
			{
				arr[i] = 0;
				for (int j = 1; i - j && j <= W; j++)
					arr[i] += arr[i - j];
			}
		}
	int sum = 0;
	int nsum = 0;
	for (int i = 1; i < K + W; i++)
		cout << arr[i]<<' ';
	for (int i = K; i < K + W; i++)
	{
		if (i <= N) nsum += arr[i];
		sum += arr[i];
	}
	cout << 1.0*nsum / sum;
    return 0;
}

