/*
1. ��, �� �Է�. �ݵ�� ��ĥ ��ǥ K�Է�. ��,�� <= 15, ���ÿ� 1�ϼ��� ����.

2. �̵��� 1,1���� c,r����. k�� ��ġ��.
	2.1 ���� ���� �������� 2by2¥�� ��-��, ��-�� 2������ => cell
	2.2 �� 2������������ �����ؼ� � �� K���� ���� ����� cell�� �������ִ�.
3. �̵�����Ǽ��� ���.
---------
���ڴ� 2�������.
���� 
���� 
1 1 1
1 2 3
1 3 6 6����.

1 1 1 ...
1 2 3
1 3 6
.       K
.
��������� ��� �迭�� ���ذ��鼭 K���� ����.
K���� ������ ���ذ��鼭 ����.
�� ���� ���ϸ� �� ����� ��.
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