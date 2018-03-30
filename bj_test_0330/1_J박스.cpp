/*
박스출력.
1. 박스크기 N입력(N<=10)
2. 박스출력(박스 외부는 #, 내부는 J)
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