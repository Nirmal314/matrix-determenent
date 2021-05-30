#include <stdio.h>
#include <stdlib.h>

int det(int matA[6][6]);

void main()
{
    int determinant;

    int matA[6][6];

    printf("\n\nEnter 6x6 matrix matA : \n\n");
    for (int u = 0; u < 6; u++)
    {
        for (int v = 0; v < 6; v++)
        {
            printf("a(%d)(%d) : ", u + 1, v + 1);
            scanf("%d", &matA[u][v]);
        }
        printf("\n");
    }
    /*matA[6][6] = {
      {1, 2, 3, 4, 5, 6},
      {5, 5, 2, 5, 2, 5},
      {5, 5, 5, 5, 5, 4},
      {2, 5, 4, 4, 4, 4},
      {4, 2, 1, 0, 1, 4},
      {1, 1, 0, 0, 0, 0}};
      
      -438
      */

    determinant = det(matA);

    printf("\n|matA| = %d \n", determinant);
}

int m = 6, n = 6;

int det(int matA[m][n])
{
    int i = m;
    int j = n;

    if (i == 2)
    {
        return (matA[0][0] * matA[1][1] - matA[1][0] * matA[0][1]);
    }

    else
    {
        int minor[i - 1][j - 1];
        int Mrow, Mcol;
        int ind;
        int sum = 0;
        int row, column;
        int sign = -1;

        for (ind = 0; ind < i; ind++)
        {
            Mrow = 0;

            for (row = 1; row < i; row++)
            {
                Mcol = 0;

                for (column = 0; column < j; column++)
                {
                    if (column == ind)
                    {
                        continue;
                    }
                    else
                    {
                        minor[Mrow][Mcol] = matA[row][column];
                    }
                    Mcol++;
                }
                Mrow++;
            }

            m = Mrow;
            n = Mcol;

            sign = -1 * sign;
            sum += sign * (matA[0][ind] * det(minor));
        }
        return sum;
    }
}