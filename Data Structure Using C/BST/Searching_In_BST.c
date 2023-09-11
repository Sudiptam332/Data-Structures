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

int recursiveSearch(struct Tree* root, int data){
    if(root == NULL){
        return 0;
    }
    else if(root->data == data){
        return 1;
    }
    else if(root->data > data){
        return recursiveSearch(root->left, data);
    }
    else{
        return recursiveSearch(root->right, data);
    }
}

int itaretiveSearch(struct Tree* root, int data){
    while(root != NULL){
        if(root->data == data){
        return 1;
        }
        else if(root->data > data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return 0;
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
   if(recursiveSearch(f1, 90)==1){
    printf("Found");
   }
   else{
    printf("Not Found");
   }

    printf("\n");

   if(itaretiveSearch(f1, 90)==1){
    printf("Found");
   }
   else{
    printf("Not Found");
   }

   return 0;
}