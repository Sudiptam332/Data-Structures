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

struct node * recursiveSearch(struct node * root, int key){
	if(root == NULL){
		return NULL;
	}
	else if(root->data == key){
		return root;
	}
	else if(root->data > key){
		return root->left;
	}
	else{
		return root->right;
	}
}

struct node * iterativeSearch(struct node * root, int key){
	while(root != NULL){
		if(root->data == key){
			return root;
		}
		else if(root->data > key){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	return NULL;
	
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
	
	struct node * ptr1 = recursiveSearch(root, 3);
	struct node * ptr2 = iterativeSearch(root, 3);
	printf("%d ", ptr1->data);
	printf("\n");
	printf("%d ", ptr2->data);
}
