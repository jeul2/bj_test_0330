/*
1. �Է� N��ŭ 1���� N���� ȯ���� ǳ���� �ִ�.
	N <= 1000

2. 1���� ��Ʈ����.
	2.1 1�ڸ��� ���� ����ŭ +�� ������, -�� ���� �̵��Ͽ� �ش� ǳ���� ��Ʈ����. (+N, -N�� �ƽù̴�)
	2.2 ��Ʈ��ǳ���� �̵�ī���ÿ� ���Խ�Ű�� �ʴ´�.

3. ������ ǳ���� ���ʴ�� ����Ѵ�.
----
ȯ���� �迭�� ����. 0���� ����. ��Ʈ���� = 0
����ǳ���� 1���϶��� �̵��� ��ų������.
*/
#include <stdio.h>

void fnDeleteBalloon(int *pSrc, int nIndex, int *pNextTarget);
void fnSearchTarget(const int *pSrc, int nMaxSize, int nCurrentIndex, int nTarget, int *pResTargetIndex);

int main()
{
	int nBalloonNum(0);
	int nData(0);
	int *pData(nullptr);


	int nMoveNum(0);
	int nTargetIndex(0);
	int nCurrentIndex(0);

	int nAliveBalloonNum(0);
	//
	freopen("input.txt", "r", stdin);

	scanf("%d", &nBalloonNum);
	pData = new int[nBalloonNum + 2]{};
	for (int i = 1; i <= nBalloonNum; ++i)
	{
		scanf("%d", &nData);
		pData[i] = nData;
	}
	
	//
	nAliveBalloonNum = nBalloonNum;
	nCurrentIndex = 1;
	while (nAliveBalloonNum != 1)
	{
		fnDeleteBalloon(pData, nCurrentIndex, &nMoveNum);
		--nAliveBalloonNum;
		fnSearchTarget(pData, nBalloonNum, nCurrentIndex, nMoveNum, &nTargetIndex);
		nCurrentIndex = nTargetIndex;
	}

	fnDeleteBalloon(pData, nCurrentIndex, &nMoveNum);
	printf("\n");

	delete[] pData;
	pData = nullptr;

	return 0;
}

void fnDeleteBalloon(int * pSrc, int nIndex, int * pNextTarget)
{
	*pNextTarget = pSrc[nIndex];
	printf("%d ", nIndex);
	pSrc[nIndex] = 0;
}

void fnSearchTarget(const int * pSrc, int nMaxSize, int nCurrentIndex, int nTarget, int * pResTargetIndex)
{
	int nCount(0);
	int nDirection(0);
	int nIndex(0);

	if (nTarget > 0)
	{
		nCount = nTarget;
		nDirection = 1;
		//++
	}
	else
	{
		nCount = nTarget * -1;
		nDirection = -1;
		//--
	}

	nIndex = nCurrentIndex;
	while (nCount != 0)
	{
		nIndex += nDirection;
		if (nIndex < 1)
		{
			nIndex = nMaxSize;
		}
		else if (nIndex > nMaxSize)
		{
			nIndex = 1;
		}
		
		if (pSrc[nIndex] != 0)
		{
			--nCount;
		}
	}

	*pResTargetIndex = nIndex;
}


