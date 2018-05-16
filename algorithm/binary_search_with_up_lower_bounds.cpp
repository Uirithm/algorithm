#include <stdio.h>

int N, T;
int dat[200001];

void Input_Data(void)
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &dat[i]);
	}
	scanf("%d", &T);
}

int Binary_Search(int s, int e, int d)
{
	int m;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (dat[m] == d) return m;
		if (dat[m] > d) e = m - 1;
		else s = m + 1;
	}

	return -1;
}

int Sequantial_Search(int s, int e, int d)
{
	int i;
	for (i = s; i <= e; i++)
	{
		if (dat[i] == d) return i;
	}
	return -1;
}

int Binary_Search_Lower(int s, int e, int d)
{
	int m, sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (dat[m] == d)
		{
			sol = m;
			e = m - 1;
		}
		else if (dat[m] > d) e = m - 1;
		else s = m + 1;
	}

	return sol;
}

int Binary_Search_Upper(int s, int e, int d)
{
	int m, sol = -1;

	while (s <= e)
	{
		m = (s + e) / 2;
		if (dat[m] == d)
		{
			sol = m;
			s = m + 1;
		}
		else if (dat[m] > d) e = m - 1;
		else s = m + 1;
	}

	return sol;
}

int main(void)
{
	int d, lower, upper;
	Input_Data();

	while (T--)
	{
		scanf("%d", &d);
		lower = Binary_Search_Lower(1, N, d);
		if (lower != -1)
		{
			upper = Binary_Search_Upper(1, N, d);
			printf("%d ", upper - lower + 1);
		}
		else
		{
			printf("0 ");
		}
	}
	return 0;
}
