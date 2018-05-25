// 단순 해쉬 활용으로 문자열 전체 비교 경우들을 줄이는 예 (300ms -> 100ms)

/*
N개의 문자열이 주어졌을 때, 동일한 문자열이 존재하는지 판단하는 프로그램을 작성하라.
 
문자열이란 사이에 공백이 없는 연속된 알파벳 소문자 열을 뜻한다.
문자열의 길이는 최소 1글자, 최대 20글자이다.
입력되는 문자열의 개수는 2개 이상 10,000개 이하이다. 

입력의 첫 번째 줄에는 입력될 문자열의 개수 N이 입력된다. 그 다음 줄에는 N개의 문자열이 공백을 사이에 두고 입력된다. 전제조건을 어긋나는 입력이 들어오는 경우는 없다.
10
alice bob libe lie libe libe alice bob alice alice 

입력에서 동일한 문자열이 존재하지 않을 경우는 "unique"를 출력한다(큰 따옴표 제외). 동일한 문자열이 발생한 경우에는 한 줄에 해당 문자열과, 문자열이 몇 번째로 입력되었는지를 출력해야 하는데, 이 경우 우선 앞에 동일한 문자열이 발견된 문자열을 출력한 다음 공백을 출력한 다음, 공백을 사이에 두고 몇 번째로 입력이 되었는지를 출력한다. 동일한 문자열이 존재하는 문자열이 여럿 발견 되었을 경우, 매 줄마다 입력된 순서대로 앞에 나온 형식에 맞춰서 출력을 한다. 자세한 사항은 입력예시를 참고한다.
alice 1 7 9 10
bob 2 8
libe 3 5 6
*/

#include <iostream>

using namespace std;

int N, CNT;

char STR[10001][21];
int HASH[10001];
bool CHK[10001];

int Make_Hash(char* str)
{
	int i;
	int val = 0;
	for (i = 0; str[i] != 0; ++i)
	{
		val += str[i];
	}

	return val;
}

bool compareStr(char* a, char* b);

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> STR[i];
		HASH[i] = Make_Hash(STR[i]);
	}

	for (int i = 1; i <= N; i++)
	if (CHK[i] == false)
	{
		int sz_a = 1;

		CHK[i] = true;

		for (int j = i + 1; j <= N; j++)
		if (HASH[i] == HASH[j] && compareStr(STR[i], STR[j]))
			CHK[j] = true, sz_a++;

		if (sz_a > 1)
		{
			cout << STR[i] << " " << i;

			for (int j = i + 1; j < N; j++)
			if (HASH[i] == HASH[j] && compareStr(STR[i], STR[j]))
				cout << " " << j;

			if (HASH[i] == HASH[N] && compareStr(STR[i], STR[N]))
				cout << " " << N;

			cout << endl;
		}
		else
			CNT++;
	}

	if (CNT == N)
		cout << "unique" << endl;

	return 0;
}

bool compareStr(char* a, char* b)
{
	bool ret = 1;

	for (int i = 0; i < 21; ++i)
	if (a[i] != b[i])
	{
		ret = 0;
		break;
	}

	return ret;
}
