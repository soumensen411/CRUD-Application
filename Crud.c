#include <stdio.h>
#include <string.h>

struct Student
{
    char id[100];
    int roll, marks;
};
struct Student N[100];
FILE *fr, *fw;
int n, i;
char id[100];

void Read_Data()
{
    fr = fopen("userdata.txt", "r");
    if (fr == NULL)
    {
        printf("Error: Unable to open file for reading.\n");
        return;
    }
    fscanf(fr, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fr, "%s%d%d", N[i].id, &N[i].roll, &N[i].marks);
    }
    fclose(fr);
}

void Update_Data()
{
    fw = fopen("userdata.txt", "w");
    if (fw == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    fprintf(fw, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(fw, "%s\n%d\n%d\n", N[i].id, N[i].roll, N[i].marks);
    }
    fclose(fw);
}

void show()
{
    Read_Data();
    for (i = 0; i < n; i++)
    {
        printf("Id : %s\nRoll: %d\nMarks: %d\n", N[i].id, N[i].roll, N[i].marks);
    }
}

int main()
{
    int q, pos;
    printf("        ---------------\n");
    printf("        1) Read Data\n        2) Delete Data\n        3) Update Data\n        4) Create Data\n");
    printf("        ---------------\n");
    printf("        > ");
    scanf("%d", &q);

    if (q == 1)
    {
        show();
    }
    else if (q == 2)
    {
        scanf("%s", id);
        Read_Data();
        pos = -1;
        for (i = 0; i < n; i++)
        {
            if (strcmp(N[i].id, id) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            for (i = pos; i < n - 1; i++)
            {
                N[i] = N[i + 1];
            }
            n--;
            Update_Data();
        }
        else
        {
            printf("ID not found.\n");
        }
        show();
    }
    else if (q == 3)
    {
        char ide[100];
        int m;
        scanf("%s%d", ide, &m);
        Read_Data();
        pos = -1;
        for (i = 0; i < n; i++)
        {
            if (strcmp(N[i].id, ide) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            N[pos].marks = m;
            Update_Data();
        }
        else
        {
            printf("ID not found.\n");
        }
        show();
    }
    else if (q == 4)
    {
        char ide[100];
        int ma, ro;
        scanf("%s%d%d", ide, &ro, &ma);
        Read_Data();
        strcpy(N[n].id, ide);
        N[n].roll = ro;
        N[n].marks = ma;
        n++;
        Update_Data();
        show();
    }
    else
    {
        printf("Invalid option.\n");
    }
    return 0;
}
