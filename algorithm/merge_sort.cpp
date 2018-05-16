#include <iostream>

#define MAX_N 100001

using namespace std;

int N, ANS;
int DATA[MAX_N][2];
int CDATA[MAX_N][2];

void init()
{
	for (int i = 0; i < N; ++i)
	{
		CDATA[i][0] = DATA[i][0];
		CDATA[i][1] = DATA[i][1];
	}
}

bool check(int p)
{
	int dist_next;
	
	init();

	for (int i = 0; i < N; ++i)
	{
		cout << i << endl;
		if (i < N - 1)
		{
			dist_next = CDATA[i + 1][0] - CDATA[i][0];
cout << i << " " <<dist_next << endl;
			if (CDATA[i][1] - p > 0)
			{
				if ((CDATA[i][1] - p) - dist_next > 0)
				{
					CDATA[i + 1][1] += CDATA[i][1] - p - dist_next;
					CDATA[i][1] = p;
				}
			}
			else
				return false;
		}
		else
		{
			if (CDATA[i][1] - p < 0)
				return false;
		}
	}



	return true;
}

void binarySearch(int s, int e)
{

	int m;

	while (s <= e)
	{
		m = (s + e) / 2;
		
		if (check(m))
		{
			ANS = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}
}

int main(void)
{
	int s = 0, e = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> DATA[i][0] >> DATA[i][1];
		if (DATA[i][1] > e)
			e = DATA[i][1];
	}

	binarySearch(1, e);

	cout << ANS << endl;

	return 0;
}