#include <stdio.h> 
#include <stdlib.h>

int m[100], count=0;

struct node {
    int data;
    struct node *left, *right;
}*tempL, *tempR;

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
        return newnode;
   }
}

void disp(struct node *root){
    if(root != NULL){
        disp(root->left);
        printf("%d ", root->data);
        disp(root->right);
    
    }
}

void mirror(struct node *root){
    if(root != NULL){
        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }
}

void main(){
    struct node *root = createitem();
    disp(root);
    mirror(root);
    disp(root);
}