/*
�ڽ����.
1. �ڽ�ũ�� N�Է�(N<=10)
2. �ڽ����(�ڽ� �ܺδ� #, ���δ� J)
*/

#include <stdio.h>

int main()
{
	int nTestCaseNum(0);
	int nData(0);

	freopen("input.txt", "r", stdin);
	scanf("%d", &nTestCaseNum);
	for (int i = 0; i < nTestCaseNum; ++i)
	{
		scanf("%d", &nData);
		for (int j = 1; j <= nData; ++j)
		{
			for (int k = 1; k <= nData; ++k)
			{
				if (j == 1 || k == 1 || j == nData || k == nData)
				{
					printf("#");
				}
				else
				{
					printf("J");
				}
			}
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}