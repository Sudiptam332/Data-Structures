#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node * f1 = createNode(10);
    struct node * f2 = createNode(20);
    struct node * f3 = createNode(30);
    struct node * f4 = createNode(40);
    struct node * f5 = createNode(50);
    struct node * f6 = createNode(60);

    f1->left = f2;
    f1->right = f3;

    f2->left = f4;
    f2->right = f5;

    f3->right = f6;


    /*
                    10
                   /  \
                 20    30
                /  \     \
              40    50    60
    */

   preOrder(f1);
   printf("\n");
   postOrder(f1);
   printf("\n");
   inOrder(f1);
   printf("\n");

   return 0;
}