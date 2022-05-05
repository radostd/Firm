#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct firm
{
    char bulstat[13];
    char name[40];
    double sum[5]; //profit in the last 5 years
    int year,day,month;
    struct firm*next;
};

struct firm* head=NULL;
struct firm*current=NULL;
//prototypes:
void start(); //creating a new firm
void add(); //adding information about the new firm
void search();
void change(); //making changes/update
void list(); //finding the average profit+listing the firm
void ShowAll(); // listing all the firms
void End(); //checking in the file

int main()
{

    char bulstat[13];
    char name[40];
    double sum[5];
    int year,day,month;
    int i,j;
    int flag=-1;

    FILE *fp;
    fp=fopen("firm","wb");

    printf("Enter the new ID: ");
    scanf("%s",&bulstat);
    j=strlen(bulstat);j++;
    printf("Enter the new NAME: ");
    scanf("%s",&name);
    i=strlen(name);i++;

    printf("Enter the new PROFIT FOR 1ST YEAR: ");
    scanf("%lf",&sum[0]);
    printf("Enter the new PROFIT FOR 2ND YEAR: ");
    scanf("%lf",&sum[1]);
    printf("Enter the new PROFIT FOR 3RD YEAR:");
    scanf("%lf",&sum[2]);
    printf("Enter the new PROFIT FOR 4TH YEAR:");
    scanf("%lf",&sum[3]);
    printf("Enter the new PROFIT FOR 5TH YEAR:");
    scanf("%lf",&sum[4]);

   printf("Enter the new YEAR: ");
    scanf("%d",&year);
    if(year>=0 && year<=2020)
    {

    }
    else
    {
        printf("!invalid year!\n");
        printf("Enter the new YEAR: ");
        scanf("%d",&year);
    }
   printf("Enter the new DAY: ");
    scanf("%d",&day);
    if (day>0 && day<=31)
    {

    }
    else
    {
        printf("!invalid day!\n");
        printf("Enter the new DAY: ");
        scanf("%d",&day);
    }
    printf("Enter the new MONTH: ");
    scanf("%d",&month);
    if(month>0 && month<=12)
    {

    }
    else
    {
        printf("!invalid month!\n");
        printf("Enter the new MONTH: ");
        scanf("%d",&month);
    }

    fwrite(&j,sizeof(int),1,fp);
    fwrite(bulstat,j,1,fp);

    fwrite(&i,sizeof(int),1,fp);
    fwrite(&name,i,1,fp);

    fwrite(&sum[0],sizeof(double),1,fp);
    fwrite(&sum[1],sizeof(double),1,fp);
    fwrite(&sum[2],sizeof(double),1,fp);
    fwrite(&sum[3],sizeof(double),1,fp);
    fwrite(&sum[4],sizeof(double),1,fp);

    fwrite(&year,sizeof(int),1,fp);
    fwrite(&day,sizeof(int),1,fp);
    fwrite(&month,sizeof(int),1,fp);
    fwrite(&flag,sizeof(int),1,fp);
    fclose(fp);

     int choice=0;

    for(;;)
    {
    printf("\t MENU \n");
    printf("0. SHOW ALL DATA, SAVED IN THE FAIL \n");
    printf("1. ADDING DATA FOR A NEW FIRM \n");
    printf("2. SEARCH AND LIST(PRINT) A FIRM BY ITS BULSTAT \n");
    printf("3. UPDATE A FIRM \n");
    printf("4. LIST OF THE FIRMS WITH BIGGEST PROFIT \n");
    printf("5. END \n");

    do
        {
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        fflush(stdin);
        }
    while(!(choice>=0 && choice<6));
      printf("%d \n",choice);
    switch(choice)
    {
        case 0:
        {
            start();
            ShowAll();
            head=NULL;
            break;

        }
        case 1:
        {
            start();
            add();
            End();
            head=NULL;
            break;
        }
        case 2:
        {   start();
            search();
            head=NULL;
            break;
        }
        case 3:
        {   start();
            change();
            End();
            head=NULL;
            break;
        }
        case 4:
        {   start();
            list();
            head=NULL;
            break;
        }
        case 5:
        {
            exit(5);
        }
    }
    }
    return 0;
}

void start()
{
    FILE *fp;
    int i;
    int flag; //for the firm
    fp=fopen("firm","rb");
    if(fp==NULL)
        {
        printf("Error open file!");
        exit(0);
        }

    while(1)
        {
        if(fread(&flag, sizeof(int), 1, fp)!=1)
            {
                printf("!Error reading!");

                exit(4);
            }
            if (flag==-1)
            break;

            struct firm *temp=(struct firm*)malloc(sizeof(struct firm));//adding new firm
            if(head==NULL)
            {
                head=temp;
                current=head;
                current->next=NULL;
            }
            else
            {
            current->next=temp;
            current=temp;
            current->next=NULL;
            }
            if((fread(temp->bulstat,flag,1,fp))!=1)
            {
                printf("!error!");
                exit (20);
            }
            if((fread(&i,sizeof(int),1,fp))!=1)
            {
                printf("!error!");

                exit (21);
            }
            if((fread(temp->name,i,1,fp))!=1)
            {
                printf("!error!");
                exit (22);
            }
            if((fread(&temp->sum[0],sizeof(double),1,fp)!=1))
            {
                printf("!error!");
                exit(23);
            }
            if((fread(&temp->sum[1],sizeof(double),1,fp)!=1))
            {
                printf("!error!");
                exit(23);
            }
            if((fread(&temp->sum[2],sizeof(double),1,fp)!=1))
            {
                printf("!error!");
                exit(23);
            }
            if((fread(&temp->sum[3],sizeof(double),1,fp)!=1))
            {
                printf("!error!");
                exit(23);
            }
            if((fread(&temp->sum[4],sizeof(double),1,fp)!=1))
            {
                printf("!error!");
                exit(23);
            }
            if((fread(&temp->year,sizeof(int),1,fp)!=1))
            {
                printf("!error!");
                exit(24);
            }
            if((fread(&temp->day,sizeof(int),1,fp)!=1))
            {
                printf("!error!");
                exit(24);
            }
            if((fread(&temp->month,sizeof(int),1,fp)!=1))
            {
                printf("!error!");
                exit(24);
            }
        }
fclose(fp);
}

void add()
{
    struct firm *temp;
    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct firm *newEl;
    newEl=(struct firm*) malloc(sizeof(struct firm));

    printf("Enter the new ID: ");
    scanf("%s",&newEl->bulstat);
    if(newEl->bulstat!=newEl->bulstat)
    {
        printf("!allready an existing id number!\n");
        printf("Enter new ID: ");
        scanf("%s", &newEl->bulstat);
    }

    printf("Enter the new NAME: ");
    scanf("%s",&newEl->name);

    printf("Enter the new PROFIT FOR THE 1ST YEAR:");
    scanf("%lf",&newEl->sum[0]);
    printf("Enter the new PROFIT FOR THE 2ND YEAR:");
    scanf("%lf",&newEl->sum[1]);
    printf("Enter the new PROFIT FOR THE 3RD YEAR:");
    scanf("%lf",&newEl->sum[2]);
    printf("Enter the new PROFIT FOR THE 4TH YEAR:");
    scanf("%lf",&newEl->sum[3]);
    printf("Enter the new PROFIT FOR THE 5TH YEAR:");
    scanf("%lf",&newEl->sum[4]);

    printf("Enter the new YEAR: ");
    scanf("%d",&newEl->year);
    if(newEl->year>=0 && newEl->year<=2020)
    {
    }
    else
    {
        printf("!invalid year!\n");
        printf("Enter the new YEAR: ");
        scanf("%d",&newEl->year);
    }
   printf("Enter the new DAY: ");
    scanf("%d",&newEl->day);
    if (newEl->day>0 && newEl->day<=31)
    {
    }
    else
    {
        printf("!invalid day!\n");
        printf("Enter the new DAY: ");
        scanf("%d",&newEl->day);
    }
    printf("Enter the new MONTH: ");
    scanf("%d",&newEl->month);
    if(newEl->month>0 && newEl->month<=12)
    {
    }
    else
    {
        printf("!invalid month!\n");
        printf("Enter the new MONTH: ");
        scanf("%d",&newEl->month);
    }
    newEl->next=NULL;
    temp->next=newEl;

    printf("\nAdd new client : SUCCESSFUL\n\n");
}

void change()
{
    char *arr;
    double chng;
    int flag=0;

    arr=(char*)malloc(20); // assigned memory space of 20 bytes
    printf("Input med ID  : \n \n");
    gets(arr);

    struct firm *temp;
    temp=(struct firm*)malloc(sizeof(struct firm));
    temp=head;

    while(temp!=NULL)
    {
    if(!(strcmp(temp->bulstat,arr))) // logical not, true only if the operand is 0
    {
    printf("\t %s \n \n",temp->name);
    current=temp;
    flag=1;
    break;
    }
  temp=temp->next;
    }

    printf("Enter the new PROFIT FOR THE 1ST YEAR");
    scanf("%lf",&temp->sum[0]);
    printf("Enter the new PROFIT FOR THE 2ND YEAR");
    scanf("%lf",&temp->sum[1]);
    printf("Enter the new PROFIT FOR THE 3RD YEAR");
    scanf("%lf",&temp->sum[2]);
    printf("Enter the new PROFIT FOR THE 4TH YEAR");
    scanf("%lf",&temp->sum[3]);
    printf("Enter the new PROFIT FOR THE 5TH YEAR");
    scanf("%lf",&temp->sum[4]);

if(flag==0) printf("Can't find ID - %s \n \n",arr);
}

void search()
{
    char *arr;
    int flag=0;
    arr=(char*)malloc(20);
    printf("Input med ID  : \n \n");
    gets(arr);
    struct firm *temp;
    temp=(struct firm*)malloc(sizeof(struct firm));
    temp=head;
    while(temp!=NULL)
    {
        if(!(strcmp(temp->bulstat,arr)))
        {
            printf("\t %s  \n \n",temp->name);
            flag=1;
            break;
        }
  temp=temp->next;
    }
    if(flag==0) printf("Can't find ID - %s \n \n",arr);
}

void list()
{
    struct firm*temp;
    double min;
    double max,sum;
    printf("Input min  : ");
    scanf("%lf",&min);
    printf("Input max  : \n \n");
    scanf("%lf",&max);
    temp=head;
    while(temp!=NULL)
    {
    sum=((temp->sum[0]+temp->sum[1]+temp->sum[2]+temp->sum[3]+temp->sum[4])/5); //finding the average profit for the 5 years
    if(sum<max && sum>min) printf("ID: %s  firm: %s \n \n", temp->bulstat, temp->name);
    temp=temp->next;
    }
}

void ShowAll()
{
      struct firm* m;
      for(m=head; m!=NULL; m=m->next)
      {
        printf("ID: %s  CLIENT: %s   DATE: %d.%d.%d \n 1ST YEAR: %.2lf 2ND YEAR: %.2lf 3RD YEAR: %.2lf 4TH YEAR: %.2lf 5TH YEAR: %.2lf \n", m->bulstat, m->name, m->year,m->day,m->month, m->sum[0],m->sum[1],m->sum[2],m->sum[3],m->sum[4]);
      }
}

void End()
{
    FILE *fp;
    int flag=-1;
    if((fp=fopen("firm","wb"))==NULL)
        {
        printf("Error open file!");
        exit(0);
        }
    struct firm *temp;
    temp=head;

    int j;
    int i;

    while(temp!=NULL)
        {
        j=strlen(temp->bulstat);j++;
        i=strlen(temp->name);i++;

        if(fwrite(&j,sizeof(int),1,fp)!=1)
        {
           printf("!error!");
           exit(1);
        }
       if(fwrite(temp->bulstat,j,1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
       if(fwrite(&i,sizeof(int),1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
        if(fwrite(temp->name,i,1,fp)!=1)
        {
            printf("!error!");
            exit(1);
        }
       if(fwrite(&temp->sum[0],sizeof(double),1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
        if(fwrite(&temp->sum[1],sizeof(double),1,fp)!=1)
        {
            printf("!error!");
            exit(1);
        }
       if(fwrite(&temp->sum[2],sizeof(double),1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
       if(fwrite(&temp->sum[3],sizeof(double),1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
       if(fwrite(&temp->sum[4],sizeof(double),1,fp)!=1)
       {
            printf("!error!");
            exit(1);
       }
       if(fwrite(&temp->year,sizeof(int),1,fp)!=1)
        {
           printf("!error!");
           exit(1);
        }
        if(fwrite(&temp->day,sizeof(int),1,fp)!=1)
        {
            printf("!error!");
           exit(1);
        }
        if(fwrite(&temp->month,sizeof(int),1,fp)!=1)
        {
           printf("!error!");
           exit(1);
        }

        temp=temp->next;
    }
     if(fwrite(&flag,sizeof(int),1,fp)!=1)
        {
           printf("!error!");
           exit(1);
        }
    fclose(fp);
}
