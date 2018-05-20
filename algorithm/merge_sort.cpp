#include<iostream>
using namespace std;

int arr[10] = { 
	1, 4, 2, 3, 0, 
	4, 4, 3, 8, 9};

int tmp[10]; // mandatory for mergeSorting

void mergeSort(int s, int e)
{
	if (s >= e) return;

	int m = (s + e) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);

	int idx1 = s;
	int idx2 = m+1;
	int tmpIdx = s;

	while (idx1 <= m && idx2 <= e)
	{
		if (arr[idx1] < arr[idx2])
			tmp[tmpIdx++] = arr[idx1++];
		else
			tmp[tmpIdx++] = arr[idx2++];
	}
	while (idx1 <= m) tmp[tmpIdx++] = arr[idx1++];
	while (idx2 <= e) tmp[tmpIdx++] = arr[idx2++];

	for (int i = s; i <= e; i++)
		arr[i] = tmp[i];
}

int main(void)
{
	mergeSort(0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}