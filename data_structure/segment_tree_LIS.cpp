#include <stdio.h>

int N;
int num[1000000];
int max_num;

int tree[1<<18];

void Input_Data(void)
{
	int i;
	scanf("%d",&N);
	for (i = 0; i < N;i++)
	{
		scanf("%d",&num[i]);
		if (max_num < num[i]) max_num = num[i];
	}
}

#define MAX(A,B) ((A)>(B) ? (A) : (B))

void Update(int n, int rs, int re, int idx, int num)
{
	int m;
	if (rs == re)
	{
		tree[n] = num;
		return;
	}
	m = (rs + re) / 2;
	if (idx <= m) Update(n * 2, rs, m, idx, num);
	else Update(n * 2+1, m+1,re, idx, num);

	tree[n] = MAX(tree[n * 2], tree[n * 2 + 1]);
}

int Query(int n, int rs, int re, int qs, int qe)
{
	int m,l,r;
	if (qs <= rs && re <= qe) return tree[n];
	if (qe < rs || re < qs) return 0;
	m = (rs + re) / 2;
	l = Query(n * 2, rs, m, qs, qe);
	r = Query(n * 2+1, m+1, re, qs, qe);

	return MAX(l, r);
}

int Find_LIS(void)
{
	int i,len;

	for (i = 0; i < N;i++)
	{
		len = Query(1, 0, max_num, 0, num[i] - 1) + 1;
		Update(1, 0, max_num, num[i], len);
	}
	return tree[1];
}

int main(void)
{
	Input_Data();

	printf("%d\n",Find_LIS());

	return 0;
}
