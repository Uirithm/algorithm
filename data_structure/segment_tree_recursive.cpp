#include <stdio.h>

/*
배열이 주어지고 특정 구간의 합을 구하는 일은 prefix sum 테이블을 만들어 손쉽게 할 수 있다. 하지만 중간에 배열의 값이 바뀌게 되면 prefix sum 배열을 새롭게 바꿔야 하기 때문에 자주 값이 바뀌는 상황이라면 비효율적인 방법이 된다.
 
배열이 주어지고 구간의 합을 구해야 하는 여러 개의 상황이 주어진다. 그리고 구간의 합을 한번 구한 뒤에는 반드시 배열상 하나의 값이 증가되는 상황이다.
 
이런 문제를 해결할 때는 Segment Tree나 Fenwick Tree와 같은 Tree를 사용하면 빠른 시간 안에 변화에 대한 갱신과 구간의 합을 얻어낼 수 있다. Segment Tree나 Fenwick Tree를 이용해서 문제들 해결해보자.
 
in
첫째 줄에는 데이터의 수 N(1<=N<=50000), 그리고 구해야 할 구간에 대한 정보의 수 Q(2<=Q<=200000) 개가 주어진다.
둘째 줄에는 배열의 데이터 Di가 N개 주어진다. (1<= Di <=100)
셋째 줄부터 Q줄에 구간에 대한 정보가 주어진다.
각 구간에 대한 정보는 Rs, Re, I, C 총 4개의 값이 주어진다.
Rs, Re는 합을 구해야 할 구간의 시작지점과 끝 지점이다. (1<= Rs ,Re <=N)
I, C는 구간의 합을 구한 후 변경해야 할 데이터에 대한 정보이다.
I는 변경할 데이터의 위치번호(1<= I <=N), C는 데이터의 증가될 값이다. (1<= Ci <=10)
 
out
각 줄에 구간의 합에 대한 결과를 출력한다.
 
in
5 3
7
8
8
8
10
4 5 3 10
1 4 5 6
4 5 3 5
 
out
18
41
24
*/

int N, Q;
int tree[1 << 17];

#define MAX(A,B) (((A)>(B)) ? (A) : (B))

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
		Update_Add(1, 1, N, i, num);
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
