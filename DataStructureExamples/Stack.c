#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//konstantinos pagkalos icsd16139
//fyladio 2 zhthma 3
#define SIZE 10
struct Stack {
int data[SIZE];

int top;
};

void Print(struct Stack myStack,struct Stack tempStack)
{
    //Emfanisi ton stoixeion tis stoibas myStack se antistrofi seira. Ta stoixeia tis
    //stoibas tha prepei na paramenoun ametablita.
    printf("ta stoixeia ths myStack: \n");
    while(myStack.top!=-1)
    {
        tempStack.top++;
        tempStack.data[tempStack.top]=myStack.data[myStack.top];
        printf("%d\n",myStack.data[myStack.top]);
        myStack.top--;
    }
    printf("ta stoixeia ths tempStack(ta stoixeia ths myStack antestramena): \n");
    while(tempStack.top!=-1)
    {
        printf("%d\n",tempStack.data[tempStack.top]);
        tempStack.top--;
    }

}
void katametrhsh(struct Stack myStack)
{
    //Katametrisi ton stoixeion tis stoibas myStack, diatirontas tin katastasi tis
    //myStack ametabliti
    printf("o arithmos twn stoixeiwn ths stoibas myStack isoytai me th timh toy top toy myStack t opoio einai iso me : %d\n",myStack.top);
}

void DeleteValue(struct Stack myStack,int stackvalue)
{
   // Diagrafi olon ton emfaniseon enos sygkekrimenou stoixeiou stackValue apo tin
    //myStack, afinontas ametabliti ti seira ton ypoloipon stoixeion tis stoibas.
    int temp = myStack.top;
    while(temp!=-1)
    {
        if(myStack.data[temp]==stackvalue)
        {
            for (int i = temp; i < myStack.top; i++){
                myStack.data[i] = myStack.data[i+1];
            }
            myStack.top--;
        }
        temp--;
    }
    printf("Oi times meta thn diagrafh:\n");
    int i = myStack.top;
    while(i!=-1)
    {
        printf("%d\n",myStack.data[i]);
        i--;
    }
}




int main ()
{
    struct Stack myStack;              //klish twn synarthsewn sto kyriws programma
    myStack.top=-1;                     //gia na emfanistoyn ta apotelesmata
    struct Stack tempStack;
    tempStack.top=-1;
    srand(time(NULL));
    while(myStack.top<SIZE -1)
    {
        myStack.top++;
        myStack.data[myStack.top]=rand()%SIZE;
    }
    Print(myStack,tempStack);
    katametrhsh(myStack);
    int stackvalue;
    printf("dwse th timh toy stackvalue \n");
    scanf("%d",&stackvalue);
    DeleteValue(myStack , stackvalue);
}
