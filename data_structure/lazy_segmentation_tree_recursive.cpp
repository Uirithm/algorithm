#include <stdio.h>

int N, M;
int tree[1<<18];
int lazy[1<<18];

void Propagation(int n, int rs, int re)
{
	if (lazy[n])
	{
		tree[n] = (re - rs + 1) - tree[n];

		if (rs != re)
		{
			lazy[n * 2] ^= 1;
			lazy[n * 2 + 1] ^= 1;
		}
		
		lazy[n] = 0;
	}
}



int Query(int n, int rs, int re, int qs, int qe)
{
	int m, l, r;

	//void Propagation(int n,int rs,int re);
	Propagation(n,rs,re);

	if (qs <= rs && re <= qe) return tree[n];
	if (re < qs || qe < rs) return 0;

	m = (rs + re) / 2;
	l = Query(n * 2, rs, m, qs, qe);
	r = Query(n * 2+1, m+1,re, qs, qe);

	return l + r;
}

void Update_Range(int n, int rs, int re, int us, int ue)
{
	int m;

	Propagation(n, rs, re);


	if (re < us || ue < rs) return;
	if (us<=rs && re<=ue)
	{
		lazy[n] ^= 1;
		Propagation(n, rs, re);
		return;
	}

	m = (rs + re) / 2;
	Update_Range(n * 2, rs, m, us, ue);
	Update_Range(n * 2 + 1, m + 1, re, us, ue);

	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main(void)
{
	int i;
	int O, S, T;
	scanf("%d %d",&N,&M);
	for (i = 0; i < M;i++)
	{
		scanf("%d %d %d",&O,&S,&T);
		switch (O)
		{
		case 0:
			Update_Range(1,1,N,S,T);
			break;
		case 1:
			printf("%d\n", Query(1, 1, N, S, T));
			break;
		}
	}
	return 0;
}
