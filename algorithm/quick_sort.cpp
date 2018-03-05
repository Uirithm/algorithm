#if 1

#include <iostream>

using namespace std;

#define DIM 10

int A[DIM] = { 1, 20, -100, 39, -99, -80, 1000, 2, 7, 55 };

void swap(int &a, int &b) 
{
	int c = a;
	a = b, b = c;
}

int choosePivot(int low, int high)
{
	return low + (high - low) / 2; // 여러 방법으로 선택 가능
}

int partition(int low, int high)
{
	int pivotIndex = choosePivot(low, high);
	int pivotValue = A[pivotIndex];

	swap(A[pivotIndex], A[high]); // 골라진 pivot은 맨 오른쪽으로 옮겨둔다.

	int storeIndex = low;

	for (int i = low; i < high; ++i) // 최저 index부터 배열값 pivotValue와 비교, 더 작으면 최저 index부터 swap해서 차례로 채워나감
		if (A[i] < pivotValue)
			swap(A[i], A[storeIndex++]);

	swap(A[storeIndex], A[high]); // pivotValue보다 더 작은 것들 바로 다음에 swap해서 pivot을 옮겨둔다.

	return storeIndex; // 옮겨진 pivot을 리턴한다.
}

void quickSort(int low, int high)
{
	if (low < high)
	{
		int pivotNewIndex = partition(low, high); // pivotNewIndex째 배열값보다 더 작고 더 큰, 둘로 나누어 줄 index 값
		quickSort(low, pivotNewIndex - 1);
		quickSort(pivotNewIndex + 1, high);
	}
}

int main()
{
	quickSort(0, DIM - 1);

	for (int i = 0; i < 10; ++i)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}

#endif
