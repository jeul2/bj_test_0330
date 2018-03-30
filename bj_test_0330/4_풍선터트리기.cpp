/*
1. 입력 N만큼 1부터 N까지 환형인 풍선이 있다.
	N <= 1000

2. 1번을 터트린다.
	2.1 1자리에 적힌 수만큼 +는 오른쪽, -는 왼쪽 이동하여 해당 풍선을 터트린다. (+N, -N이 맥시미니)
	2.2 터트린풍선은 이동카운팅에 포함시키지 않는다.

3. 터지는 풍선을 차례대로 출력한다.
----
환형을 배열로 구현. 0값은 없다. 터트린다 = 0
남은풍선이 1개일때는 이동을 시킬수없다.
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


