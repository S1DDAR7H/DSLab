// circular q operations

#include <stdio.h>

int front = -1, rear = -1, max_size=5, CQ[5];

void enQ(int item){
    if(front == (rear+1)%max_size){
        printf("full\n");
    }
    else{
        rear = (rear+1)%max_size;
        CQ[rear] = item;
        if(front == -1){
            front ++;
        }
    }
}

void deQ(){
    if (front == -1){
        printf("empty\n");
    }
    else{
        printf("%d is deleted\n", CQ[front]);
        if(front == rear){
            front = -1;
            rear = -1;
        }
        front = (front + 1)%max_size;
    }
}

void disp(){
    if (front == -1){
        printf("empty\n");
    }
    else{
        if(front <= rear){
            for(int i=front; i<rear; i++){
                printf("%d\n", CQ[i]);
            }
        }
        else{
            for(int i=front; i<max_size; i++){
                printf("%d\n", CQ[i]);
            }
            for(int i=0; i<=rear; i++){
                printf("%d\n", CQ[i]);
            }
        }
    }
}
void main(){
    enQ(1);
    enQ(2);
    enQ(3);
    enQ(4);
    enQ(5);
    disp();
    deQ();
    deQ();
    disp();
    enQ(4);
    enQ(5);
    disp();
}