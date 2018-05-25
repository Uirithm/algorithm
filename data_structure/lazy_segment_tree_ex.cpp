/*
https://www.acmicpc.net/problem/8980
with
입력의 첫 줄은 마을 수 N과 트럭의 용량 C가 빈칸을 사이에 두고 주어진다.
N은 2이상 100,000이하 정수이고, C는 1이상 100,000,000이하 정수이다.
다음 줄에, 보내는 박스 정보의 개수 M이 주어진다. M은 1이상 200,000이하 정수이다.
다음 M개의 각 줄에 박스를 보내는 마을번호, 박스를 받는 마을번호, 보내는 박스 개수(1이상 10,000이하 정수)를 나타내는 양의 정수가 빈칸을 사이에 두고 주어진다.
박스를 받는 마을번호는 보내는 마을번호보다 크다.
*/
#include <stdio.h>

#define MAX(A, B) (A > B ? A : B)

int N, C;
int M;
typedef struct
{
	int s;
	int e;
	int box;
}INFO;
INFO info[200000], tmp[200000];

int tree[1 << 18];
int lazy[1 << 18];

void Propagation(int n, int rs, int re)
{
	if (lazy[n])
	{
		tree[n] += lazy[n];

		if (rs != re)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

int Query(int n, int rs, int re, int qs, int qe)
{
	int m, l, r;
	Propagation(n, rs, re);

	if (qs <= rs && re <= qe) return tree[n];
	if (qe < rs || re < qs) return 0;

	m = (rs + re) / 2;
	l = Query(2 * n, rs, m, qs, qe);
	r = Query(2 * n + 1, m + 1, re, qs, qe);
	
	return MAX(l, r);
}

void Update(int n, int rs, int re, int us, int ue, int num)
{
	int m;
	Propagation(n, rs, re);

	if (re < us || ue < rs) return;
	if (us <= rs && re <= ue)
	{
		lazy[n] += num;
		Propagation(n, rs, re);
		return;
	}

	m = (rs + re) / 2;
	Update(n * 2, rs, m, us, ue, num);
	Update(n * 2 + 1, m + 1, re, us, ue, num);

	tree[n] = MAX(tree[n * 2], tree[n * 2 + 1]);
}

void Merge_Sort(int s, int e)
{
	int m;
	int idx1, idx2, idxtmp;
	if (s >= e) return;
	m = (s + e) / 2;
	Merge_Sort(s, m);
	Merge_Sort(m + 1, e);

	idx1 = s; idx2 = m + 1; idxtmp = s;
	while (idx1 <= m && idx2 <= e)
	{
		if (info[idx1].e < info[idx2].e)
			tmp[idxtmp++] = info[idx1++];
		else
			tmp[idxtmp++] = info[idx2++];
	}

	while (idx1 <= m) tmp[idxtmp++] = info[idx1++];
	while (idx2 <= e) tmp[idxtmp++] = info[idx2++];

	for (idxtmp = s; idxtmp <= e; idxtmp++)
		info[idxtmp] = tmp[idxtmp];
}

void Input_Data(void)
{
	int i;
	scanf("%d %d", &N, &C);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &info[i].s, &info[i].e, &info[i].box);
	}
}

int Greedy(void) // changed to using the segment tree with the lazy propagation
{
	int i, j, box;
	int sum = 0;

	for (i = 0; i < M; i++)
	{
		box = C - Query(1, 1, N, info[i].s, info[i].e - 1);
		box = (box > info[i].box) ? (info[i].box) : (box);
		sum += box;

		if (box>0)
		{
			Update(1, 1, N, info[i].s, info[i].e - 1, box);
		}
	}
	return sum;
}


int main(void)
{
	Input_Data();
	Merge_Sort(0, M - 1);

	printf("%d\n", Greedy());

	return 0;
}
