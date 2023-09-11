#include<stdio.h>
#include<stdlib.h>

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

int parenthesisMatch(char * ch){
    struct Stack * s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));

    for(int i=0; ch[i]!='\0'; i++){
        if(ch[i] == '('){
            push(s, ch[i]);
        }
        if(ch[i] == ')'){
            pop(s);
        }
    }

    if(isEmpty(s)){
        return 1;
    }
    return 0;
}

int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}


int parenthesisMatch2(char * exp){
    struct Stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){ 
              return 0;  
            }
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    char * ch = "[4-6]((8){(9-8)})";
    if(parenthesisMatch2(ch)){
        printf("Parenthesis Matched");
    }
    else{
        printf("Parenthesis not Matched");
    }
    return 0;
}