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
	return low + (high - low) / 2; // ���� ������� ���� ����
}

int partition(int low, int high)
{
	int pivotIndex = choosePivot(low, high);
	int pivotValue = A[pivotIndex];

	swap(A[pivotIndex], A[high]); // ����� pivot�� �� ���������� �Űܵд�.

	int storeIndex = low;

	for (int i = low; i < high; ++i) // ���� index���� �迭�� pivotValue�� ��, �� ������ ���� index���� swap�ؼ� ���ʷ� ä������
		if (A[i] < pivotValue)
			swap(A[i], A[storeIndex++]);

	swap(A[storeIndex], A[high]); // pivotValue���� �� ���� �͵� �ٷ� ������ swap�ؼ� pivot�� �Űܵд�.

	return storeIndex; // �Ű��� pivot�� �����Ѵ�.
}

void quickSort(int low, int high)
{
	if (low < high)
	{
		int pivotNewIndex = partition(low, high); // pivotNewIndex° �迭������ �� �۰� �� ū, �ѷ� ������ �� index ��
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
