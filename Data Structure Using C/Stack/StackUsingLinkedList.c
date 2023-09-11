#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    //int length;
    struct Node * next;
};

void printEle(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){
        printf("Stack Underflow!!!\n");
        return 1;
    }
    return 0;
}

int isFull(struct Node* top){
    struct Node* s = (struct Node *)malloc(sizeof(struct Node));
    if(s == NULL){
        printf("Stack Overflow!!!\n");
        return 1;
    }
    return 0;
}

struct Node* push(struct Node* top, int val){
    if(isFull(top)){
        return top;
    }
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    s->data = val;
    s->next = top;
    top = s;
    return top;
}

struct Node * pop(struct Node* top){
    if(isEmpty(top)){
        return top;
    }
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    s = top;
    top = top->next;
    free(s);
    return top;
}

/*int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}*/

int peek(struct Node* ptr, int idx){
    int i = 1;
    while(i != idx){
        ptr = ptr->next;
        i++;
    }
    return ptr->data;
}

/*int peek(struct Node* top, int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}*/

int stackTop(struct Node* top){
    return top->data;
}

int stackButtom(struct Node* ptr){
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main(){
    struct Node* top = NULL;
    //top->length = 0;
    /*
    top = push(top, 5);
    top = push(top, 4);
    top = push(top, 3);
    top = push(top, 2);
    top = push(top, 1);

    top = pop(top);
    //pop(&top);
    printEle(top);

    printf("Peek : %d\n", peek(top, 2));
    printf("StackTop : %d\n", stackTop(top));
    printf("StackButtom : %d\n", stackButtom(top));
    */
    while (1)
    {
        printf("------- Menu -------\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Choose a Option : ");
        int choose, value, pos;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1: printf("Enter the value : ");
                scanf("%d", &value);
                top = push(top, value);
                break;
        case 2: top = pop(top);
                break;
        case 3: printf("Enter the position : ");
                scanf("%d", &pos);
                printf("value : %d", peek(top, pos));
                break;
        case 4: printEle(top);
                break;
        case 5: exit(0);       
        }
    }

    return 0;
}