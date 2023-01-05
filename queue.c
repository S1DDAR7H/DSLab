//queue operations

#include <stdio.h>

int front = -1, rear = -1, max_size = 5, Q[5];

void enQ(int item){
    if(rear == max_size-1){
        printf("Q full\n");
    }
    else{
        rear ++;
        Q[rear] = item;
        if(front == -1){
            front ++;
        }
    }
}

void deQ(){
    if(front == -1){
        printf("Q empty\n");
    }
    else{
        printf("%d is deleted\n", Q[front]);
        front ++;
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }
}

void disp(){
    for(int i=front; i<rear+1; i++){
        printf("%d\n", Q[i]);
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
