#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int x;
    struct node *next;
};
void addNode(struct node **head,int x)//Synartisi me onoma addNode i opoia tha prosthetei enan neo kombo se mia apli
//syndedemeni lista me tetoio tropo oste na diatireitai i fthinousa diataxi. I synartisi
//tha dexetai os parametrous tin lista (mono to head), kai ta dedomena pou tha
//apothikeytoun ston kombo (enas akeraios arithmos).
{
    if(*head==NULL)
    {
        *head=(struct node *)malloc(1*sizeof(struct node));
        (*head)->x=x;
        (*head)->next=NULL;
    }
    else
    {
        struct node *temp=(struct node *)malloc(1*sizeof(struct node));
        temp->x=x;
        temp->next=NULL;
        if(x>(*head)->x)
        {
            temp->next=*head;
            *head=temp;
        }
        else
        {
            struct node *temp1=*head;
            int flag=0;
            while(temp1->next!=NULL)
            {
                struct node *temp2=temp->next;
                if(x>temp2->x)
                {
                    temp1->next=temp;
                    temp->next=temp2;
                    flag=1;
                }
                temp1=temp1->next;
            }
            if(flag==0)
            {
                temp1->next=temp;
            }
        }
    }
}

char* toString (struct node *head)
//Synartisi me onoma toString i opoia tha dexetai os parametro mia apli syndedemeni
//lista kai tha epistrefei mia symboloseira me ola ta stoixeia tis listas xorismena me
//komma.
{
    int N=0;
    char *String=(char *)malloc(N*sizeof(char));
    //prepei na kseroyme ton synoliko arithmo twn pshfiwn olwn twn arithmwn sth lista
    //giati kathe pshfio tha apotellei ena stoixeio ston pinala string
    while(head!=NULL)
    {
        int n=Pshfia(head->x);
        N+=n;
        String=(char *) realloc(String, N);
        for(int i=n;i>0;i--)
        {
            String[N-i]=((int)(head->x/(pow(10,n-1)))%10)+48;//+48 to grafoyme epeidh h timh toy xarakthra 0 ston ascii einai 48ara an prosthesoyme to 48 se opoiodhpote monopshfio arithmo tha broyme th timh toy xarakthra aytoy toy arithmoy ston pinaka ascii
        }
        head=head->next;
        if(head!=NULL)
        {
            N++;
            String=(char *) realloc(String, N);
            String[N-1]=',';
        }
    }

    return String;
}
int Pshfia(int x)//ypologismos twn pshfiwn toy aritmoy x epiprostheth synarthsh
{
    int i=0;
    while(x!=0)
    {
        i++;
        x=x/10;
    }
    return i;
}
void deleteList(struct node **head)
//Synartisi deleteList i opoia tha diagrafei olous tous kombous tis listas pou dexetai
//os parametro
{
    *head=NULL;
}
void deleteElement(struct node **head,int x)
//Synartisi me onoma deleteElement i opoia tha dexetai os parametro mia apli
//syndedemeni lista kai enan akeraio arithmo, tha anazita olous tous kombous pou
//periexoun to sygkekrimeno arithmo kai tha tous diagrafei.
{
    while(1)
    {
        if((*head)->x==x)
        {
            *head=(*head)->next;
        }
        else
        {
            break;
        }
    }
    struct node *temp=*head;
    while(temp!=NULL)
    {
        struct node *temp1=temp->next;
        if(temp1->x==x)
        {
            temp=temp1->next;
        }
        temp=temp->next;

    }
}
bool containsList(struct node *head,int x)
//Synartisi containsList i opoia tha elegxei an ena stoixeio pou dexetai os parametro
//emperiexetai stin lista. I synartisi tha prepei na epistrefei true an isxyei kai false se
//antitheti periptosi.
{

  while(head!=NULL)
    {
        if(head->x==x)
        {
            return true;
        }
    }
    return false;
}
int countList(struct node *head)
//Synartisi countList i opoia metra olous tous kombous tis listas pou dexetai os
//parametro.
{
    int i=0;
    while (head!=NULL)
    {
        i++;
        head= head->next;
    }
    return i;
}
int countElement(struct node *head,int x)
//Synartisi countElement i opoia tha dexetai os parametro mia apli syndedemeni lista
//kai enan akeraio arithmo kai tha metra poses fores emperiexetai i timi ayti stous
//kombous tis listas.
{
    int i=0;
    while (head!=NULL)
    {
        if(head->x==x)
        {
            i++;
        }
        head= head->next;
    }
    return i;
}
int getElement(struct node *head,int x)
//Synartisi getElement i opoia tha dexetai os parametro mia apli syndedemeni lista kai
//enan akeraio arithmo (thesi kombou) kai tha epistrefei ta dedomena (akeraia timi) tou
//kombou sti sygkekrimeni thesi.
{
    int i=0;
    while (head!=NULL)
    {
        if(i==x)
        {
            return head->x;
        }
        i++;
        head= head->next;
    }
    return NULL;
}

int firstLocationList(struct node *head,int x)
//Synartisi firstLocationList i opoia tha dexetai os parametro mia apli syndedemeni
//lista kai enan akeraio arithmo kai tha epistrefei tin thesi tis 1is emfanisis tou arithmou
//stin lista.
{
    int i=0;
    while (head!=NULL)
    {
        if(head->x==x)
        {
            return i;
        }
        i++;
        head= head->next;
    }
    return -1;
}
int lastLocationList(struct node *head,int x)
//Synartisi lastLocationList i opoia tha dexetai os parametro mia apli syndedemeni
//lista kai enan akeraio arithmo kai tha epistrefei tin teleytaia emfanisi tou arithmou
//stin lista.

{
    int i=0,j=-1;
    while (head!=NULL)
    {
        if(head->x==x)
        {
            j=i;
        }
        i++;
        head= head->next;
    }
    return j;
}
void  removeDuplicates(struct node *head)
//Synartisi removeDuplicates i opoia diagrafei oles tis pollaples emfaniseis timon
//stous kombous tis listas pou dexetai os parametro.
{
    while (head!=NULL)
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            struct node *temp1=temp->next;
            if(head->x==temp1->x)
            {
                temp->next=temp1->next;
            }
            temp=temp->next;
        }
        head=head->next;
    }
}



int main()
{
    struct node *head;
    head=NULL;
    int flag=1;
    while(flag)   //klish twn synarthsewn se ena menu
    {
        int choice;
        int a,a1,a2,a3,a4,a5,a6;
        printf("0:exit,1:addNode,2:toString,3:deleteList,4:deleteElement,5:containsList,6:countList,7:countElement,8:getElement,9:firstLocationList,10: lastLocationList,11:removeDuplicates \n");
        scanf("%d",&choice);

        char *String;
        switch(choice)
        {
        case 0:
            flag=0;
            break;
        case 1:

            printf("dwse enan akeraio gia na prostethei sth lista\n");
            scanf("%d",&a);
            addNode(&head,a);
            break;
        case 2:
            String=toString(head);
            puts(String);
            break;
        case 3:
            deleteList(&head);
            break;
        case 4:
            printf("dwseenan akeraio arithmo \n");
            scanf("%d",&a1);
            deleteElement(&head,a1);
            break;
        case 5:
            printf("dwseenan akeraio arithmo gia anazhthsh \n");
            scanf("%d",&a2);
            containsList(head,a2);
            break;
        case 6:
            printf("%d",countList(head));
            break;
        case 7:
            printf("dwse enan akeraio arithmo gia metrhsh \n");
            scanf("%d",&a3);
            printf("%d",countElement(head,a3));
            break;
        case 8:
            printf("dwse thesh gia emfanish \n");
            scanf("%d",&a4);
            printf("%d",getElement(head,a4));
            break;
        case 9:
           printf("dwse stoixeio gia prwth emfanish \n");
           scanf("%d",&a5);
           printf("%d",firstLocationList(head,a5));
            break;
        case 10:
             printf("dwse stoixeio gia teleytaia emfanish \n");
             scanf("%d",&a6);
              printf("%d",lastLocationList(head,a6));
            break;
        case 11:
           removeDuplicates(head);
            break;
        }
    }

}
