#include <stdio.h>

void penjumlahan(int a[3][3], int b[3][3], int c[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void perkalian(int a[3][3], int b[3][3], int c[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transpos(int a[3][3], int b[3][3]) {
    int i, j;
    int c[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[j][i] = a[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a[i][j] = c[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[j][i] = b[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            b[i][j] = c[i][j];
        }
    }
    printf("Matrix A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a [3] [3], b [3] [3],c [3] [3];
    int i,j,menu;
    do
    {
    printf("1. penjumlahan\n");
    printf("2. perkalian\n");
    printf("3. transpose\n");
    printf("4. keluar\n");
    printf("Masukan Pilihan Menu : ");
    
    scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
           printf("Enter elements of 3x3 matrix a:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &a[i][j]);
                   }
            }
            i = 0, j =0;
            printf("Enter elements of 3x3 matrix b:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &b[i][j]);
                    }
            }
            penjumlahan(a,b,c);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("%d ", c[i][j]);
                }
            printf("\n");
            }
            
			break;

        case 2:
            printf("Enter elements of 3x3 matrix a:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &a[i][j]);
                   }
            }
            i = 0, j =0;
            printf("Enter elements of 3x3 matrix b:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &b[i][j]);
                    }
            }

            perkalian(a,b,c);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("%d ", c[i][j]);
                }
            printf("\n");
            }
			break;

        case 3:
            printf("Enter elements of 3x3 matrix a:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &a[i][j]);
                   }
            }
            i = 0, j =0;
            printf("Enter elements of 3x3 matrix b:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    scanf("%d", &b[i][j]);
                    }
            }

            transpos(a,b);

            printf("Matrix A:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("%d ", a[i][j]);
                }      
            printf("\n");
            }

            printf("Matrix B:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("%d ", b[i][j]);
                }
            printf("\n");
            }
            break;
            
            default:
            break;
        }
    }while (menu != 4);
}