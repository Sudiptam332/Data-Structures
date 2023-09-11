#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
	int height;
};

int max(int val1, int val2){
	return (val1>val2)?val1:val2;
}

int getHeight(struct node * n){
	if(n == NULL){
		return 0;
	}
	return n->height;
}

struct node * createNode(int data){
	struct node * ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->height = 1;
	return ptr;
}

int getBalanceFactor(struct node * n){
	if(n == NULL){
		return 0;
	}
	return getHeight(n->left)-getHeight(n->right);
}

struct node * rightRotation(struct node * y){
	struct node * x = y->left;
	struct node * t2 = x->right;
	
	x->right = y;
	y->left = t2;
	
	x->height = max(getHeight(x->left), getHeight(x->right))+1;
	y->height = max(getHeight(y->left), getHeight(y->right))+1;
	
	return x;
}


struct node * leftRotation(struct node * x){
	struct node * y = x->right;
	struct node * t2 = y->left;
	
	y->left = x;
	x->right = t2;
	
	x->height = max(getHeight(x->left), getHeight(x->right))+1;
	y->height = max(getHeight(y->left), getHeight(y->right))+1;
	
	return y;
}

struct node * insert(struct node * n, int data){
	if(n == NULL){
		return createNode(data);
	}
	else if(data < n->data){
		n->left = insert(n->left, data);
	}
	else if(data > n->data){
		n->right = insert(n->right, data);
	}
	else{
		printf("%d already exit. Can not be inserted",data);
	}
	
	n->height = max(getHeight(n->left), getHeight(n->right))+1;
	int bf = getBalanceFactor(n);
	
	//Left Left case
	if(bf>1 && data < n->left->data){
		return rightRotation(n);
	}
	//Right Right case
	else if(bf<-1 && data > n->right->data){
		return leftRotation(n);
	}
	//Left Right case
	else if(bf>1 && data > n->left->data){
		n->left = leftRotation(n->left);
		return rightRotation(n);
	}
	//Right Left case
	else if(bf<-1 && data < n->right->data){
		n->right = rightRotation(n->right);
		return leftRotation(n);
	}
	return n;
}

void preOrder(struct node * ptr){
	if(ptr != NULL){
		printf("%d ", ptr->data);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

int main(){
    struct Node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}


