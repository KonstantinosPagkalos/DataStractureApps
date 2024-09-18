#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//konstantinos pagkalos icsd16139

#define SIZE 25
struct Queue {
    char **name;//theloyme enan pinaka me ta onomta twn pelatwn, alla ta onomata einai me thn seira toys pinakes, ara thelw ena pinaka me kathe kelaki toy na einai allos pinakas
    int number[SIZE];

    int front;
    int rear; // Τελευταίο στοιχείο της ουράς
};

void add_customer(struct Queue myQueue){
    //Eisodos pelati stin oura anamonis (o pelatis anamenei exypiretisi)
    if ((myQueue.rear+1)%SIZE== myQueue.front){
        printf("H oura einai geath");
        return;
    }
    myQueue.rear++;
    if (myQueue.rear > SIZE){
        myQueue.rear = 0;
    }
    myQueue.name[myQueue.rear] = (char *)malloc(SIZE*sizeof(char));
    printf("dose onoma kai epitheto pelath");
    gets(myQueue.name[myQueue.rear]);
}

void remove_customer(struct Queue myQueue){
    //Exodos pelati apo tin oura (o pelatis exypiretithike)
    if (myQueue.front != myQueue.rear){//an to front einai diaforetiko apo to rear, dhladh an uparei pelaths sthn oura
        myQueue.front++;
    }
}

int main ()
{
    struct Queue myQueue;
    myQueue.front=myQueue.rear=0;
    myQueue.name = (char **)malloc(SIZE*sizeof(char*));
    int flag = 1;
    int c;
    while (flag){
        printf("0:exit 1:neos pelaths 2:afereshpelath 3:emfnhsh epomenoy pelath 4:plhthos pelatwn sthn oura\n");
        scanf("%d" , &c);
        fflush(stdin);
        switch(c){
            case 1:
                add_customer(myQueue);
                break;
            case 2:
                remove_customer(myQueue);
                break;
            case 3:
                printf("%s" , myQueue.name[myQueue.front]);.// Emfanisi stoixeion pelaton pros exypiretisi
                break;
            case 4:
                if (myQueue.front < myQueue.rear){
                    printf("%d" , myQueue.rear - myQueue.front);
                }
                else{
                    printf("%d" , SIZE - myQueue.front + myQueue.rear);//Plithos pelaton pros exypiretisi
                }

        }
    }
}
