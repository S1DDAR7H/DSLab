#include <stdio.h>

int max = 5, front = -1, rear = -1;

struct q{
    int data;
    int prio;
} q[5];

void eQ(int item, int priority){
    if(rear == max-1){
        printf("FUll\n");
    }
    else{
        rear ++;
        q[rear].data = item;
        q[rear].prio = priority;
        if(front == -1){
            front ++;
        }
    }
}

void sort(){
    int t;
    for (int i = front; i <= rear; i++)
    {
        for (int j = front; j < rear; j++)
        {
            if(q[j].prio>q[j+1].prio){
                t=q[j].data;
                q[j].data = q[j+1].data;
                q[j+1].data = t;

                t=q[j].prio;
                q[j].prio = q[j+1].prio;
                q[j+1].prio = t;
            }
        }
        
    }
}

void dQ(){
    if(front == -1){
        printf("Empty\n");
    }
    else{
        sort();
        printf("%d is deleted", q[front].data);
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }
}
void traverse(){
    if(front == -1){
        printf("nothing much to display");
    }
    else{
            sort();
            for (int i = front; i < rear; i++)
            {
                printf("%d ",q[i]);
            }
        
    }
}
int main()
{
    int choice;
   while(1){
        printf("\n1.enQueue\n2.deQueue\n3.Traverse\n choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to enQueue : ");
                int n;
                scanf("%d",&n);
                printf("Enter the priority to enQueue : ");
                int p;
                scanf("%d",&p);

                eQ(n,p);
                break;
            case 2: dQ();
                    break;
            case 3: traverse();
                    break;
            case 0: break;
            
            default:
                printf("invalid choice");
        }
    }
    return 0;
}