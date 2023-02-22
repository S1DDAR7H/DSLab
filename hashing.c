#include <stdio.h>
#include <stdlib.h>
#define m 7

int a[m];

typedef struct hashtable{
    int data;
    struct hashtable *next;
}hashtable;

//chaining
int hash(int key){
    return key%m;
}

void chaining(){
    int key,n;
    struct hashtable **t = (struct hashtable **)malloc(sizeof(struct hashtable*)*m);
    for(int i=0;i<m;i++){
        t[i] = NULL;
    }
    printf("Enter No of elements:");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &key);
        int h = hash(key);
        hashtable *newnode = (struct hashtable *)malloc(sizeof(struct hashtable));
        newnode->next = NULL;
        newnode->data = key;
        if(t[h] != NULL){
            newnode->next = t[h];
        }
        else{
            t[h] = newnode;
        }
    }
    printf("\n The List are\n");
	for(int i=0;i<m;i++){
        printf("List %d:",i);
        if(t[i] == NULL){
            printf("Empty\n");
        }
        else{
            hashtable *tmp = t[i];
            while(tmp != NULL){
                printf("%d", tmp->data);
                tmp=tmp->next;
            }
            printf("\n");
        }
    }
}

//open addressing
void hashing(int item){
    int i,h,fl=0;
    for(i=0;i<m;i++){
        int h1=item%m;
        h = (h1+i)%m;
        if(a[i] == -1){
            a[i] = item;
            fl=1;
            break;
        }
        else{
            fl=0;
        }
    }
    if(fl == 0){
        printf("Table Overflow\n");
    }
    else{
        for(i=0;i<m;i++){
            printf("%d  ", a[i]);
        }
        printf("\n");
    }
}

void openaddressing(){
    int i,item;
    for(i=0;i<m;i++){
        a[i] = -1;
    }
    for(i=0;i!=-1;i++){
        printf("Enter element:");
        scanf("%d", &a[i]);
        hashing(item);
    }
}

void main(){
    int ch,e;
    do
    {
    printf("The hash function using is key%7\n");
    printf("MENU\n");
    printf("1. Open addressing\n2. Chaining\n");
    printf("Read your option(1/2)");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        openaddressing();
        break;
        case 2:
        chaining();
        break;
    }
    printf("Do you continue?(0 for end,1 for continue)\n");
    scanf("%d",&e);
    }while(e!=0);
}
