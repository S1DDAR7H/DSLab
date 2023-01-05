#include <stdio.h> 
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createitem(){
    int item;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data(-1 for no data)");  
    scanf("%d", &item); 
    if(item == -1){
        return 0;
    }
    else{
        newnode->data = item;
        printf("Enter LChild of %d: ", item);
        newnode->left = createitem();
        printf("Enter RChild of %d: ", item);
        newnode->right = createitem();
   }
}

void disp(struct node *root){
    printf("%d", root->data);
    disp(root->left);
    disp(root->right);
}

void main(){
    struct node *root = createitem();
    disp(root);
}