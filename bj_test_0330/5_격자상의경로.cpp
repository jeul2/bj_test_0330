/*
1. 행, 렬 입력. 반드시 거칠 좌표 K입력. 행,렬 <= 15, 동시에 1일수는 없음.

2. 이동은 1,1에서 c,r까지. k를 거치고.
	2.1 가장 적은 움직임은 2by2짜리 우-하, 하-우 2가지다 => cell
	2.2 이 2가지움직임을 조합해서 어떤 점 K까지 가는 방법은 cell로 나눌수있다.
3. 이동경우의수를 출력.
---------
ㅁ자는 2가지방법.
ㅁㅁ 
ㅁㅁ 
1 1 1
1 2 3
1 3 6 6가지.

1 1 1 ...
1 2 3
1 3 6
.       K
.
행렬정보를 담는 배열로 더해가면서 K까지 진행.
K부터 끝가지 더해가면서 진행.
이 둘을 곱하면 총 경우의 수.
*/

#include <stdio.h>

int main()
{
	int nRow(0);
	int nCol(0);
	int nMustVisitData(0);

	int nMustRow(0);
	int nMustCol(0);
	int nData(0);

	int nRes(0);

	int **ppData(nullptr);
	//
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &nRow, &nCol, &nMustVisitData);
	ppData = new int*[nRow + 1]{};
	for (int i = 1; i <= nRow; ++i)
	{
		ppData[i] = new int[nCol + 1]{};
	}

	if (nMustVisitData == 0)
	{
		nMustRow = nRow;
		nMustCol = nCol;
	}
	else
	{
		nMustRow = nMustVisitData / nCol + 1;//2
		nMustCol = nMustVisitData % nCol;//3
		if (nMustVisitData % nCol == 0)
		{
			nMustRow = nMustVisitData / nCol;
			nMustCol = nCol;
		}
			
	}
	printf("%d %d\n", nMustRow, nMustCol);

	for (int i = 1; i <= nMustRow; ++i)
	{
		for (int j = 1; j <= nMustCol; ++j)
		{
			if (i == 1 || j == 1)
			{
				ppData[i][j] = 1;
			}
			else
			{
				ppData[i][j] = ppData[i - 1][j] + ppData[i][j - 1];
			}
			printf("[%d]", ppData[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", ppData[nMustRow][nMustCol]);

	for (int i = nMustRow; i <= nRow; ++i)
	{
		for (int j = nMustCol; j <= nCol; ++j)
		{
			if (i == nMustRow || j == nMustCol)
			{
				ppData[i][j] = ppData[nMustRow][nMustCol];
			}
			else
			{
				ppData[i][j] = ppData[i - 1][j] + ppData[i][j - 1];
			}
			printf("[%d]", ppData[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", ppData[nRow][nCol]);

	for (int i = 1; i <= nRow; ++i)
	{
		delete[] ppData[i];
		ppData[i] = nullptr;
	}
	delete[] ppData;
	ppData = nullptr;

	return 0;
}