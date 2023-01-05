// stack operations

#include <stdio.h>
int max_size = 5;
int top = -1, stack[5];

void push(int item){
    if (top == max_size){
        printf("stack full");
    }
    else{
        top ++;
        stack[top] = item;
    }
}

void pop(){
    if(top == -1){
        printf("Stack empty\n");
    }
    else{
        printf("%d\n", stack[top]);
        top --;
    }
}

void disp(){
    for(int i=0; i<top+1; i++){
        printf("%d\n", stack[i]);
    }
}

void main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    disp();
    pop();
    pop();
    disp();
}