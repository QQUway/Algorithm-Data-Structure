#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char Scholars_Grading[10];
};

void inputScholars(struct Scholars *p,struct Scholars *px)
{
    printf("Nim  : ");
    scanf("%d", &p->Scholars_Nim);
    printf("Name : ");
    scanf(" %[^\n]", p->Scholars_name);
    printf("Major : ");
    scanf(" %[^\n]", p->Scholars_Major);
    printf("Nilai Tugas : ");
    scanf("%f", &px->Scholars_Nilai.tugas);
    printf("Nilai Uts   : ");
    scanf("%f", &px->Scholars_Nilai.uts);
    printf("Nilai Uas   : ");
    scanf("%f", &px->Scholars_Nilai.uas);
}

void showScholars(struct Scholars p[100],struct Scholars px[100],int k)
{
    int i;
    printf("                                      List Of Student Information                       \n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|No. |          Name                |              NIM             |            Jurusan           |    Tugas   |     UTS    |     UAS    |    Grade   |\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i<k ;i++)
    {
        px[i].Scholars_Total = px[i].Scholars_Nilai.tugas * 0.3 + px[i].Scholars_Nilai.uts * 0.3 + px[i].Scholars_Nilai.uas * 0.4;

        if (px[i].Scholars_Total >= 95.0) {
            strcpy(px[i].Scholars_Grading, "A+");
        } else if (px[i].Scholars_Total >= 85.0) {
            strcpy(px[i].Scholars_Grading, "A");
        } else if (px[i].Scholars_Total >= 80.0) {
            strcpy(px[i].Scholars_Grading, "A-");
        } else if (px[i].Scholars_Total >= 75.0) {
            strcpy(px[i].Scholars_Grading, "B+");
        } else if (px[i].Scholars_Total >= 70.0) {
            strcpy(px[i].Scholars_Grading, "B");
        } else if (px[i].Scholars_Total >= 65.0) {
            strcpy(px[i].Scholars_Grading, "C");
        } else if (px[i].Scholars_Total >= 60.0) {
            strcpy(px[i].Scholars_Grading, "C-");
        } else if (px[i].Scholars_Total >= 55.0) {
            strcpy(px[i].Scholars_Grading, "D");
        } else if (px[i].Scholars_Total >= 0.0) {
            strcpy(px[i].Scholars_Grading, "E");
        }

        printf("|%-3d.| %-28s | 000000%-22d | %-28s | %-10.2f | %-10.2f | %-10.2f | %-10s |\n"    ,i+1,
                                                                            p[i].Scholars_name,
                                                                            p[i].Scholars_Nim,
                                                                            p[i].Scholars_Major,
                                                                            px[i].Scholars_Nilai.tugas,
                                                                            px[i].Scholars_Nilai.uts,
                                                                            px[i].Scholars_Nilai.uas,
                                                                            px[i].Scholars_Grading);
    }//65 +36 = 108
    //5 +30 + 30 + 12 +12 +12 



}

//Rifqi H

int main()
{

    struct Scholars p[100];
    struct Scholars px[100];
    int i = 0,k = i;
    int j;
    int menu;

    FILE *fD = fopen("dataMahasiswa.txt", "r");
	while(!feof(fD)) {
	 	struct Scholars st;
	 	fscanf(fD, "%d#%[^#]#%[^\n]\n", &st.Scholars_Nim, st.Scholars_name, st.Scholars_Major);
	 	p[i] = st;
	 	i++;
	}

	i = 0;
	FILE *fN = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fN)) {
		struct Scholars sc;
		fscanf(fN, "%d#%f#%f#%f#%f#%s", &sc.Scholars_Nim, &sc.Scholars_Nilai.tugas, &sc.Scholars_Nilai.uts, &sc.Scholars_Nilai.uas , &sc.Scholars_Total, sc.Scholars_Grading);
		px[i] = sc;
		i++;
	}		
	
	fclose(fD);
	fclose(fN);
    k = i;

    do
    {
        system("cls");
        printf("Welcome to Simple Student Database (%d/100)\n",i);
        printf("1. Show all Students\n");
        printf("2. Input Students\n");
        printf("3. Exit\n");
        printf("Choose : ");
        scanf("%d",&menu);
        switch (menu)
            {
            case 1:
                showScholars(p,px,k);
                system("pause");
                break;
            case 2:
                if(i<100)
                {
                    inputScholars(&p[i],&px[i]);
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
    fD = fopen("dataMahasiswa.txt", "w");
    for(j = 0; j < i; j++) {
 	fprintf(fD, "000000%d#%s#%s\n", p[j].Scholars_Nim, p[j].Scholars_name, p[j].Scholars_Major);
    }		
    fN = fopen("nilaiMahasiswa.txt", "w");
    for(j = 0; j < i; j++) {
	fprintf(fN, "%d#%f#%f#%f#%.2f#%s\n", p[j].Scholars_Nim, px[j].Scholars_Nilai.tugas, px[j].Scholars_Nilai.uts, px[j].Scholars_Nilai.uas , px[j].Scholars_Total, px[j].Scholars_Grading);
    }	
    fclose(fD);
    fclose(fN);

}
//Rifqi Habib Ur Rahman
