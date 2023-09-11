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

struct node * insert(struct node * root, int key){
	struct node * prev = NULL;
	while(root != NULL){
		prev = root;
		if(root->data == key){
			printf("Can not be insert, %d already present.\n", key);
			return root;
		}
		else if(root->data > key){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	struct node * newNode = createNode(key);
	if(key < prev->data){
		prev->left = newNode;
	}
	else{
		prev->right = newNode;
	}
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
	insert(root, 6);
	inOrder(root);
}
