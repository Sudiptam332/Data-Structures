#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node* createNode(int data){
	struct node * ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct node * inorderPredecessor(struct node * root){
	root = root->left;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

struct node * delete(struct node * root, int key){
	struct node * iPre;
	if(root == NULL){
		return NULL;
	}
	else if(root->left == NULL && root->right == NULL){
		free(root);
		return NULL;
	}
	
	else if(key < root->data){
		root->left = delete(root->left, key);
	}
	else if(key > root->data){
		root->right = delete(root->right, key);
	}
	else{
		iPre = inorderPredecessor(root);
		root->data = iPre->data;
		root->left = delete(root->left, iPre->data);
	}
	return root;
}

void inOrder(struct node * root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

int main(){
	struct node * root = createNode(5);
	struct node * p1 = createNode(3);
	struct node * p2 = createNode(6);
	struct node * p3 = createNode(1);
	struct node * p4 = createNode(4);
	
	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p1->right = p4;
	
	inOrder(root);
	printf("\n");
	root = delete(root, 3);
	inOrder(root);
}
