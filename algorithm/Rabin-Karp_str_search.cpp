#include <stdio.h>
int N, M;
char str[3000001];
char word[51];

int cnt;
int pos[3000001];

int str_cmp_n(char* str1, char* str2, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i]) return str1[i] - str2[i];
	}
	return 0;
}

void Input_Data(void)
{
	scanf("%d", &N);
	scanf("%s", str);
	scanf("%d", &M);
	scanf("%s", word);
}

unsigned long long int Make_Hash(char *str,int len)
{
	int i;
	unsigned long long int hash = 0;
	for (i = 0; i < len; i++)
	{
		hash = (hash << 8) + str[i];
	}
	return hash;
}



int Find_Word(void)
{
	unsigned long long hash_mask;
	unsigned long long hash_str;
	unsigned long long hash_word;
	int i;
	hash_str = Make_Hash(str,M); 
	hash_word = Make_Hash(word, M);

	if (M >= 8)
		hash_mask = 0xffffffffffffffff;
	else
		hash_mask = (1ULL << (8 * M)) - 1;

	if (hash_str == hash_word && !str_cmp_n(str, word, M))
	{
		pos[cnt++] = 0;
	}

	for (i = 1; i < N-M;i++)
	{
		hash_str = ((hash_str << 8) + str[i + M - 1]) & hash_mask;
		if (hash_str == hash_word && !str_cmp_n(&str[i], word, M))
		{
			pos[cnt++] = i;
		}
	}
}

int main(void)
{
	int i;
	Input_Data();
	if (N < M)
	{
		printf("-1\n");
	}
	else
	{
		Find_Word();
		if (cnt == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", cnt);
			for (i = 0; i < cnt; i++) printf("%d ", pos[i] + 1);
		}
		
	}
	return 0;
}
