#include <stdio.h>
struct Scholars
{
char Scholars_Major[30];
char Scholars_name[30];
float Scholars_GPA;
};

void inputScholars(struct Scholars *p)
{
    printf("Name : ");
    fflush(stdin);
    scanf("%[^\n]s",p->Scholars_name);
    fflush(stdin);
    printf("Major : ");
    fflush(stdin);
    scanf("%[^\n]s",p->Scholars_Major);
    fflush(stdin);
    printf("GPA : ");
    scanf("%f",&p->Scholars_GPA);
}

void showScholars(struct Scholars p[20],int k)
{
    int i;
    printf("                      List Of Student Information                       \n");
    printf("------------------------------------------------------------------------\n");
    printf("|No. |          Name                |          Major      |     GPA    |\n");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i<k ;i++)
    {
        printf("|%-3d.| %-28s | %-19s | %-10.2f |\n",i+1,p[i].Scholars_name,p[i].Scholars_Major,p[i].Scholars_GPA);
    }
}
int main()
{
    struct Scholars p[20];

    int i = 0,k = i;
    int menu;
    do
    {
        system("cls");
        printf("Welcome to Simple Student Database (%d/20)\n",i);
        printf("1. Show all Students\n");
        printf("2. Input Students\n");
        printf("3. Exit\n");
        printf("Choose : ");
        scanf("%d",&menu);
        switch (menu)
            {
            case 1:
                showScholars(p,k);
                system("pause");
                break;
            case 2:
                if(i<20)
                {
                    inputScholars(&p[i]);
                    i++;
                    printf("New Students Added\n");
                    k = i;
                }
                else
                {
                    printf("Dataset Full\n");
                }
                system("pause");
                break;
            default:

                break;
            }
    } while (menu != 3 );
}