/*
1. 현재 빈병수,	발견한 빈병수, 새병으로바꾸는데 필요한 빈병수 입력
	<1000, <1000, 1<x<2000
2. 빈병으로 콜라를 마시면 빈병하나가 생긴다.
3. 마신 콜라수를 출력.
*/
#include <stdio.h>

int main()
{
	int nCurrentBottle(0);
	int nFindedBottle(0);
	int nNeedBottlesForExchangeCoke(0);

	int nSumBottles(0);
	int nCountOfDrink(0);
	//
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &nCurrentBottle, &nFindedBottle, &nNeedBottlesForExchangeCoke);

	nSumBottles = nCurrentBottle + nFindedBottle;
	while (nSumBottles >= nNeedBottlesForExchangeCoke)
	{
		++nCountOfDrink;
		++nSumBottles;
		nSumBottles -= nNeedBottlesForExchangeCoke;
	}

	printf("%d\n", nCountOfDrink);

	return 0;
}