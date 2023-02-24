#include <stdio.h>

struct grade
{
    float tugas,uts,uas;
};
struct Scholars
{
    char Scholars_Major[30];
    char Scholars_name[30];
    int Scholars_Nim;
    struct grade Scholars_Nilai;
    float Scholars_Total;
    char Scholars_Grading;
};

void inputScholars(struct Scholars *p)
{
    printf("Nim  : ");
    fflush(stdin);
    scanf("%d",&p->Scholars_Nim);
    printf("Name : ");
    fflush(stdin);
    scanf("%[^\n]s",p->Scholars_name);
    fflush(stdin);
    printf("Major : ");
    fflush(stdin);
    scanf("%[^\n]s",p->Scholars_Major);
    fflush(stdin);
    printf("Nilai Tugas : ");
    scanf("%d",&p->Scholars_Nilai.tugas);
    fflush(stdin);
    printf("Nilai Uts   : ");
    scanf("%d",&p->Scholars_Nilai.uts);
    fflush(stdin);
    printf("Nilai Uas   : ");
    scanf("%d",&p->Scholars_Nilai.uas);
    fflush(stdin);

}

void showScholars(struct Scholars p[20],int k)
{
    int i;
    printf("                                      List Of Student Information                       \n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("|No. |          Name                |              NIM              |     Tugas    |      UTS     |      UAS     |\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i<k ;i++)
    {
        printf("|%-3d.| %-28s | %-28d | %-10.2f | %-10.2f | %-10.2f |\n"    ,i+1,
                                                                            p[i].Scholars_name,
                                                                            p[i].Scholars_Major,
                                                                            p[i].Scholars_Nim,
                                                                            p[i].Scholars_Nilai.tugas,
                                                                            p[i].Scholars_Nilai.uts,
                                                                            p[i].Scholars_Nilai.uas);
    }//65 +36 = 108
    //5 +30 + 30 + 12 +12 +12 



}

void datawrite(struct Scholars Newscholar[100],int k)

{
    FILE *fout = fopen("output.txt","w");
        fprintf(fout,"%d#%s$%s#%.2f#%d\n",  Newscholar[k].Scholars_Nim,
                                            Newscholar[k].Scholars_name,
                                            Newscholar[k].Scholars_Major,
                                            Newscholar[k].Scholars_Total,
                                            Newscholar[k].Scholars_Grading);
    fclose(fout);
}

int main()
{
    int i = 0,k = i;
    int menu;

    struct Scholars p[20];
    struct Scholars Newscholar[100];

    FILE *fp = fopen("data.txt","r");
    while(!feof(fp)){
        
        fscanf(fp,"%d#%[^#]#%[^#]#",Newscholar[i].Scholars_Nim,Newscholar[i].Scholars_name,Newscholar[i].Scholars_Major);
        i++;
    }
    fclose(fp);

    FILE *fout = fopen("output.txt","w");
    for(i = 0; i<3 ; i++)
    {
        fprintf(fout,"%d#%s$%s#%.2f#%d\n",  p[i].Scholars_Nim,
                                            p[i].Scholars_name,
                                            p[i].Scholars_Major,
                                            p[i].Scholars_Total,
                                            p[i].Scholars_Grading);
    }
    fclose(fout);
    
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
                    for(int counter = 0; counter <100 ; counter++)
                    {
                        if (p[counter].Scholars_Nim == Newscholar[i].Scholars_Nim)
                        {
                            p[counter].Scholars_Nilai.tugas = Newscholar[i].Scholars_Nilai.tugas;
                            p[counter].Scholars_Nilai.uts = Newscholar[i].Scholars_Nilai.uts;
                            p[counter].Scholars_Nilai.uas = Newscholar[i].Scholars_Nilai.uas;
                            datawrite(&Newscholar[100],counter);
                        
                        }
                        else 
                        {
                            
                        }
                    }
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
