#include <cstdio>

#define NDATA (5)
#define MAX_IDT (15)
#define LEAF_START (MAX_IDT / 2 + 1)

int data[NDATA] = { 9, 8, 1, 7, 2 };
int IDT[MAX_IDT + 1];

void initIDT()
{
	for (int i = 0; i <= MAX_IDT; ++i)
		IDT[i] = 0x7fffffff;

	for (int i = 0; i < NDATA; ++i)
		IDT[LEAF_START + i] = data[i];
}

void update(int leaf)
{
	int l, r, p = leaf / 2;
	if (leaf % 2 == 0) l = leaf, r = l + 1;
	else l = leaf - 1, r = leaf;

	while (p > 0)
	{
		int sum_lr = IDT[l] + IDT[r];

		if (IDT[p] != sum_lr)
		{
			IDT[p] = sum_lr;

			if (p % 2 == 0) l = p, r = l + 1;
			else l = p - 1, r = p;

			p /= 2;
		}
		else break;
	}
}

int sum_interval(int a, int b)
{
	int sum = 0;
	int s = LEAF_START + a;
	int e = LEAF_START + b;

	if (a == b) return IDT[s];

	if (s % 2 == 1)	sum += IDT[s++];
	if (e % 2 == 0) sum += IDT[e--];

	int depth = (e - s) / 2 + 1;
	int p = s;
	for (int i = 0; i < depth; ++i)
		p /= 2;

	sum += IDT[p];

	return sum;
}

int main()
{
	initIDT();

	for (int i = 0; i < NDATA; ++i)
		update(LEAF_START + i);

	//IDT[LEAF_START + 2] = 5;
	//update(LEAF_START + 2);

	for (int i = LEAF_START; i < LEAF_START + NDATA; ++i)
		printf("%d ", IDT[i]);

	printf("\nsum_interval: %d\n", sum_interval(0, 4));

	return 0;
}
