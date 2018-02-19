/* Ad Hoc Algorithms
아이디어가 떠오르기 힘든 유형이나, 아이디어가 떠오르면 매우 간단히 문제가 해결되는 문제이다.
대회나 시험에는 잘 나오지는 않지만 매우 유용한 알고리즘이다.

1. Anagram 문제
동일한 문자로 이루어진 단어를 anagram이라 한다. 예를 들어
flow/wolf, nameless/salesman, adreno/radeon

n개의 단어가 주어지고, 단어들의 길이의 합은 W라 하자.
이 때 O(W) 시간에 문제를 해결할 수 있는가?

두 문자열 비교를 생각했을 때 각각의 문자열의 길이를 x,y라고 하면
O(x+y)만에 확인이 가능하다고 하자. 그러면 이러한 각각의 문자열들이 n개가 있다고 다시 가정하면,
O(n^2)만큼 비교하여 전체 anagram을 찾아낼 수 있다. 그러나, 실제로 O(n^2)번 비교하는 것은 단지 O(sigma x_i n)번의 비용이 든다.
since, 모든 단어에 대해 O(x1 n + x2 n + x3 n + ... ) = O(Wn)

- 두 단어를 O(x+y)로 비교를 하는 것은 어떻게 할 것인가? -> 각 단어들을 카운팅 정렬해두자.
- 전체 anagram의 수는 어떻게 할 것인가? -> 정렬된 단어들을 사전순으로 다시 정렬하고, 중복된 단어들의 조합


*/

#if 1

#include<iostream>
using namespace std;

int main(void)
{
	return 0;
}

#endif