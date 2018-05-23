#include <stdio.h>

/*
광규네 집에는 총 N개의 스위치가 있고 1번부터 N번까지 번호가 붙어있다. 광규는 취미가 이 스위치들을 켜고 끄는 것이다. 광규는 2가지 방법으로 스위치를 갖고 논다.
1.    A번부터 B번 사이의 스위치 상태를 반전시킨다.
2.    C번부터 D번 사이의 스위치 중 켜져 있는 스위치의 개수를 세는 것이다.
광규가 위와 같은 조작을 하였을 때의 결과를 알아보자

in
첫 번째 줄에는 스위치의 개수 N과 처리할 일의 개수 M이 공백으로 구분되어 입력된다 (2≤N≤100,000) (1≤M≤100,000)
두 번째 줄부터 M줄에 걸쳐 처리할 일의 정보가 3개의 정수 형태로 입력된다. 3개의 정수 O, S, T는 공백으로 구분되어 있다. O의 값이 0이면 S부터 T까지 스위치 상태를 반전시킨다. 1이면 S부터 T까지 스위치 중 켜져 있는 스위치의 개수를 묻는 것이다.
초기에는 모든 스위치가 꺼져 있다.

out
입력 중 켜져 있는 스위치의 개수를 묻는 명령에 대한 답을 한 줄에 하나씩 출력한다.

in
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4

out
1
2
*/

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
