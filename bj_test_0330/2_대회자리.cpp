/*
1. �Է� ������ P, �ڸ� M.
	1.1 ������ P�� �ɰ���� �ڸ� �ε��� �Է�.
2. �ߺ��Ǹ� 1���� ������ �������� ���ɴ´�.

3. �ڸ��� �Ҵ���� �ʴ� ���� ī��Ʈ�� ���.
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