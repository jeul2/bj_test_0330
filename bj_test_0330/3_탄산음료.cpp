/*
1. ���� �󺴼�,	�߰��� �󺴼�, �������ιٲٴµ� �ʿ��� �󺴼� �Է�
	<1000, <1000, 1<x<2000
2. ������ �ݶ� ���ø� ���ϳ��� �����.
3. ���� �ݶ���� ���.
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