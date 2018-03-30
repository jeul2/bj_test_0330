/*
1. 입력 참가자 P, 자리 M.
	1.1 참가자 P가 앉고싶은 자리 인덱스 입력.
2. 중복되면 1명을 제외한 나머지는 못앉는다.

3. 자리가 할당되지 않는 수를 카운트후 출력.
*/

#include <stdio.h>

int main()
{
	int nTestNum(0);
	int nPeopleNum(0);
	int nSiteNum(0);

	int *pSite(nullptr);
	int nData(0);
	int nSumCannotSit(0);
	//
	//freopen("input.txt", "r", stdin);
	scanf("%d", &nTestNum);
	for (int i = 0; i < nTestNum; ++i)
	{
		scanf("%d %d", &nPeopleNum, &nSiteNum);
		pSite = new int[nSiteNum + 1]{};
		for (int j = 0; j < nPeopleNum; ++j)
		{
			scanf("%d", &nData);
			pSite[nData] += 1;
		}

		nSumCannotSit = 0;
		for (int j = 1; j <= nSiteNum; ++j)
		{
			if (pSite[j] > 1)
				nSumCannotSit += pSite[j] - 1;
		}

		printf("%d\n", nSumCannotSit);
		delete[] pSite;
		pSite = nullptr;
	}

	return 0;
}