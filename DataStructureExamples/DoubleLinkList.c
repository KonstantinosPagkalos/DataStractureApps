#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Product
{
    char Product_code [10];//Kodikos proiontos (monadikos gia kathe proion)
    char kataskeyasths [10];//Kataskeyastis proiontos
    char perigrafh [20];//Perigrafi
    float timh;//Timi
    bool availability;//Diathesimotita
    struct Product *next;//Ena deikti pros ton epomeno kombo
    struct Product *previous;//Ena deikti pros ton proigoumeno kombo

};
void add_Product(char *Product_code,char *kataskeyasths,char *perigrafh,float timh, struct Product **head)
//eisagogi neon proionton stin lista. I sygkekrimeni leitourgia tha prepei na
//dexetai ta stoixeia tou neou proiontos. Se periptosi omos pou brei stin yparxousa
//lista, oti yparxei idi to proion (idio kodikos proiontos), den tha prepei na epitrepetai i
//eisagogi. I eisagogi tha ginetai panta sto telos tis listas.
{
    if(*head==NULL)
    {
        (*head)=(struct Product*) malloc(sizeof(struct Product));
        strcpy((*head)->Product_code,Product_code);
        strcpy((*head)->kataskeyasths,kataskeyasths);
        strcpy((*head)->perigrafh,perigrafh);
        (*head)->timh=timh;
        (*head)->availability=true;
        (*head)->next=NULL;
        (*head)->previous=NULL;
    }
    else
    {
        struct Product *temp=*head;
        while(temp->next!=NULL) //ayth h while tha ginetai mexri na ftasoyme sto teleytaio stoixeio,otan teleiwei to temp
        {                       //tha periexei to  teleytaio stoixeio ths listas kai etsi tha boroymea prosthesoyme to epomeno stoixeio amesws meta to telytaio
            if(strcmp(temp->Product_code,Product_code)==0)
            {
                return ; //an yparxei hdh to product code den prepei na kanei prosthhkh sth lista ara teleiwnei h synarthsh
            }
            temp=temp->next;
        }
        struct Product *neoProduct=(struct Product*) malloc(sizeof(struct Product));
        strcpy(neoProduct->Product_code,Product_code);
        strcpy(neoProduct->kataskeyasths,kataskeyasths);
        strcpy(neoProduct->perigrafh,perigrafh);
        neoProduct->timh=timh;
        neoProduct->availability=true;
        neoProduct->previous=temp;
        neoProduct->next=NULL;
        temp->next=neoProduct;
    }
}
void print(struct Product *head)
//emfanisi olokliris tis listas ton proionton.
{
    while(head!=NULL)
    {
        printf("Product_code : %s \n kataskeyasths : %s \n perigrafh : %s \n timh: %.2f \n availability: %d \n",head->Product_code,head->kataskeyasths,head->perigrafh,head->timh,head->availability);
        printf("-------------------------\n");
        head=head->next;
    }

}


void search_by_code(char *productcode,struct Product *head)
{
    //anazitisi enos proiontos stin lista me basi ton kodiko tou. Kathe fora pou i
//anazitisi tha einai epityxis tha emfanizontai ola ta stoixeia tou proiontos kai o kombos
//ston opoio einai apothikeymeno to proion tha prepei na metaferetai stin kefali tis
//listas.
    while(head!=NULL)
    {
        if (strcmp(productcode,head->Product_code)==0)
        {
            printf("Product_code : %s \n kataskeyasths : %s \n perigrafh : %s \n timh: %f \n availability: %d \n",head->Product_code,head->kataskeyasths,head->perigrafh,head->timh,head->availability);
        }
        head=head->next;
    }
}

void Delete(char *productcode,struct Product **head)
//Tin diagrafi enos proiontos. O xristis tha prepei na eisagei ton kodiko tou proiontos
//pou epithymei na diagrapsei.
{
    if(strcmp((*head)->Product_code,productcode)==0)
    {
        *head=(*head)->next;
        (*head)->previous=NULL;
    }
    else
    {
        struct Product *temp = *head;
        while(temp!=NULL)
        {
            if(strcmp(temp->Product_code,productcode)==0)
            {
                (temp->previous)->next=temp->next;
                (temp->next)->previous=temp->previous;
                return ;
            }
            temp=temp->next;
        }
    }
}
void show_number_of_products_in_list(struct Product *head)
//Tin emfanisi tou plithous ton proionton pou einai apothikeymena sti lista.
{
    int i=0;
    while(head!=NULL)
    {
        i++;
        head=head->next;
    }
    printf("o arithmos proiontwn einai :%d\n",i);
}

int main ()
{
    struct Product *head=NULL;
    int flag=1;

    while(flag)
    {
        int choice;
       char product_code[10],kataskeyasths[10],perigrafh[20];
       float timh;
        printf("1.addProuct \n 2.PRINT \n 3.search_by_code \n 4.delete_by_product_code \n 5.Show_nember_of_products_stored_in_list \n");
        scanf("%d",&choice);
        fflush(stdin);
        char *String;
        switch(choice)     // klish twn synarthsewn se ena menu
        {
        case 0:
            flag=0;
            break;
        case 1:
            printf("dwse enan kwdiko proiontos\n");
            gets(product_code);
            fflush(stdin);
            printf("dwse kataskeyasth\n");
            gets(kataskeyasths);
            fflush(stdin);
            printf("dwse perigrafh\n");
            gets(perigrafh);
            fflush(stdin);
            printf("dwse timh \n");
            scanf("%f",&timh);
            add_Product(product_code,kataskeyasths,perigrafh,timh,&head);
            break;
        case 2:
            print(head);
            break;
        case 3:
            printf("dwse ena productCode: \n");
            gets(product_code);
            fflush(stdin);
            search_by_code(product_code,head);
            break;
        case 4:
            printf("dwse ena productCode: \n");
            gets(product_code);
            fflush(stdin);
            Delete(product_code,&head);
            break;
        case 5:
            show_number_of_products_in_list(head);

        }
    }

}
