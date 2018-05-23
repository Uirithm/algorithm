#include <stdio.h>

int N, Q;
int tree[1 << 17];

#define MAX(A,B) (((A)>(B)) ? (A) : (B))

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
	else Update(n * 2 + 1, m + 1, re, idx, num);

	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void Update_Add(int n, int rs, int re, int idx, int num)
{
	int m;
	if (rs == re)
	{
		tree[n] += num;
		return;
	}

	m = (rs + re) / 2;

	if (idx <= m) Update_Add(n * 2, rs, m, idx, num);
	else Update_Add(n * 2 + 1, m + 1, re, idx, num);

	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void Input_Data(void)
{
	int i, num;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num);
		Update(1, 1, N, i, num);
	}
}

int Query(int n, int rs, int re, int qs, int qe)
{
	int m, l, r;
	if (qs <= rs && re <= qe) return tree[n];
	if (re < qs || qe < rs) return 0;

	m = (rs + re) / 2;
	l = Query(n * 2, rs, m, qs, qe);
	r = Query(n * 2 + 1, m + 1, re, qs, qe);

	return l+r;
}

int main(void)
{
	int Rs,Re,I,C;
	Input_Data();

	while (Q--)
	{
		scanf("%d %d %d %d", &Rs, &Re,&I,&C);
		printf("%d\n", Query(1, 1, N, Rs, Re));
		Update_Add(1, 1, N, I, C);
	}
	return 0;
}
