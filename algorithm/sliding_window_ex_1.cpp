// https://www.acmicpc.net/problem/2531
// with 2≤N≤3,000,000, 2≤d≤3,000, 2≤k≤3,000 (k≤N), 1≤c≤d

#include <stdio.h>

int MAX, N, D, K, C;
int dish[3002999];
int sushi_cnt[3001];

void Input_Data(void)
{
	int i;
	scanf("%d %d %d %d", &N, &D, &K, &C);

	for (i = 0; i < N; i++)
		scanf("%d", &dish[i]);

	for (i = 0; i < K - 1; i++)
		dish[N + i] = dish[i];
}

int Get_Max(void)
{
	int i;
	int cnt = 1;
	int max_cnt;
	sushi_cnt[C] = 1;

	for (i = 0; i < K; i++)
	{
		sushi_cnt[dish[i]]++;
		if (sushi_cnt[dish[i]] == 1) cnt++;
	}

	max_cnt = cnt;

	for (i = 1; i < N; i++)
	{
		sushi_cnt[dish[i - 1]]--;
		if (sushi_cnt[dish[i - 1]] == 0) cnt--;

		sushi_cnt[dish[i + K - 1]]++;
		if (sushi_cnt[dish[i + K - 1]] == 1) cnt++;

		if (max_cnt < cnt) max_cnt = cnt;
	}

	return max_cnt;
}

int main()
{
	Input_Data();

	printf("%d\n", Get_Max());

	return 0;
}
