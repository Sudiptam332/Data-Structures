#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
};

struct Tree * createNode(int data){
    struct Tree * t = (struct Tree *)malloc(sizeof(struct Tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void inOrder(struct Tree* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Tree* root){
    static struct Tree * prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct Tree * f1 = createNode(60);
    struct Tree * f2 = createNode(40);
    struct Tree * f3 = createNode(70);
    struct Tree * f4 = createNode(30);
    struct Tree * f5 = createNode(50);
    struct Tree * f6 = createNode(90);

    f1->left = f2;
    f1->right = f3;

    f2->left = f4;
    f2->right = f5;

    f3->right = f6;


    /*
                    60
                   /  \
                 40    70
                /  \     \
              30    50    80
    */

   inOrder(f1);
   printf("\n");
   printf("%d", isBST(f1));

   return 0;
}