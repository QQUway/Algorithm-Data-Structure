#include<stdio.h>

int main()
{
    int randomNumber[5] = { 10,24,234,345,234};
    int i;
    
    printf("isi awal array\n");
    for (i=0; i<6 ; i++)
    {
        printf("randomNumber[%d] = [%d]\n", randomNumber[i]);
    }
    return 0;
}