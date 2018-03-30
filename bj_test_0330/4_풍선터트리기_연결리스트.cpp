#include <stdio.h>
#include <crtdbg.h>

struct S_LIST
{
	int nData;
	int nIndex;
	S_LIST *pNext;
	S_LIST *pPrevious;
};

void fnDeleteNode(S_LIST *pTarget);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	S_LIST *pHead(nullptr);
	S_LIST *pNew(nullptr);
	S_LIST *pCur(nullptr);
	int nNumber(0);
	int nData(0);
	//
	freopen("input.txt", "r", stdin);
	scanf("%d", &nNumber);

	scanf("%d", &nData);
	pHead = new S_LIST{};
	pHead->nData = nData;
	pHead->nIndex = 1;
	pCur = pHead;
	for (int i = 1; i < nNumber; ++i)
	{
		scanf("%d", &nData);
		pNew = new S_LIST{};
		pNew->nData = nData;
		pNew->nIndex = i + 1;

		pCur->pNext = pNew;
		pNew->pPrevious = pCur;

		pCur = pCur->pNext;
	}
	pCur->pNext = pHead;
	pHead->pPrevious = pCur;
	pCur = nullptr;
	pNew = nullptr;

	//
	fnDeleteNode(pHead);
	pHead = nullptr;
	
	return 0;
}

void fnDeleteNode(S_LIST * pTarget)
{
	S_LIST *pPre(nullptr);
	S_LIST *pNext(nullptr);
	pPre = pTarget->pPrevious;
	pNext = pTarget->pNext;
	if (pPre == pNext)
	{
		printf("%d ", pTarget->nIndex);
		printf("%d\n", pTarget->pNext->nIndex);
		delete pNext;
		pNext = nullptr;
		delete pTarget;
		pTarget = nullptr;
		return;
	}

	pPre->pNext = pNext;
	pNext->pPrevious = pPre;
	printf("%d ", pTarget->nIndex);

	int nCount(0);
	S_LIST *pCur(nullptr);
	nCount = pTarget->nData;
	if (nCount > 0)
	{
		pCur = pNext;
		while (nCount != 1)
		{
			pCur = pCur->pNext;
			--nCount;
		}
		fnDeleteNode(pCur);
	}
	else
	{
		pCur = pPre;
		while (nCount != -1)
		{
			pCur = pCur->pPrevious;
			++nCount;
		}
		fnDeleteNode(pCur);
	}
	delete pTarget;
	pTarget = nullptr;
}
