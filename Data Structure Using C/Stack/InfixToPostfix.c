#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char * arr;
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

void push(struct Stack* s, char val){
    if(isFull(s)){
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct Stack* s){
    if(isEmpty(s)){
        return 0;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int stackTop(struct Stack* s){
    return s->arr[s->top];
}

int isOparetor(char infix){
    if(infix=='+' || infix=='-' || infix=='*' || infix=='/'){
        return 1;
    }
    return 0;
}

int presedence(char infix){
    if(infix=='*' || infix=='/'){
        return 3;
    }
    else if(infix=='+' || infix=='-'){
        return 2;
    }
    return 0;
}

char * infixToPostfix(char * infix){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char * postfix = (char *)malloc((sizeof(infix)+1) * sizeof(char));
    int i=0, j=0;

    while(infix[i] != '\0'){
        if(!isOparetor(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(presedence(infix[i]) > presedence(stackTop(s))){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main(){
    char arr[] = "a-b/c";
    printf("Postfix : %s", infixToPostfix(arr));
    return 0;
}