#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct Stack* s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack* s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

void push(struct Stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow!!!, %d cannot be Stored\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!!!\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d has been popped from Stack\n", val);
        return val;
    }
}

int peek(struct Stack *ptr, int pos){
    if(ptr->top-pos+1 < 0){
        printf("Not Valide");
    }
    else{
        return ptr->arr[ptr->top-pos+1];
    }
}

int stackTop(struct Stack* ptr){
    return ptr->arr[ptr->top];
}

int stackButtom(struct Stack* ptr){
    return ptr->arr[0];
}

int main(){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));

    printf("Before Push\n");
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    printf("\n");

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    //push(s, 6); Overflow Condition.

    printf("After Push\n");
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    printf("\n");

    pop(s);
    printf("\n");

    printf("Peeked ele : %d\n", peek(s, 1));
    printf("StackTop : %d\n", stackTop(s));
    printf("StackButtom : %d\n", stackButtom(s));

    

    return 0;

}