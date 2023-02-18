#include <stdio.h>

void upper(char kata[255])
{
    int i=0;    
    
    for( ;kata[i]!='\0';i++)
    {

        if((kata[i]>='a' && kata[i]<='z'))
            kata[i]=kata[i]-32;
    }

    printf("%s",kata);
}

void lower(char kata[255])
{
    int i=0;
    
    for( ;kata[i]!='\0';i++)
    {
        if(kata[i]>='A' && kata[i]<='Z')
            kata[i]=kata[i]+32;
    }

    printf("%s",kata);
}

void switcher(char kata[255])
{
     int i=0;
     
    for( ;kata[i]!='\0';i++)
    {

        if((kata[i]>='a' && kata[i]<='z'))
            {kata[i]=kata[i]-32;}

        else if((kata[i]>='A' && kata[i]<='Z'))
            {kata[i]=kata[i]+32;}
    }

    printf("%s",kata);
}

int main()
{
    int selection;
    char kata[100];
    do
    {
		system("cls");
        printf("1. Uppercase\n");
        printf("2. Lowercase\n");
        printf("3. Switching\n");
        printf("4. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &selection);
        getchar();
        switch (selection)
        {
        case 1:
            printf("Masukkan text : ");
            fgets(kata, sizeof(kata), stdin);
            upper(kata);
            system("pause");
			break;
        case 2:
            printf("Masukkan text : ");
            fgets(kata, sizeof(kata), stdin);
            lower(kata);
            system("pause");
			break;
        case 3:
            printf("Masukkan text : ");
            fgets(kata, sizeof(kata), stdin);
            switcher(kata);
			system("pause");
            break;
        default:
            break;
        }
    } while (selection != 4);
    return 0;
}