#include<stdio.h>
#include<stdlib.h>

struct Array_ADT{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct Array_ADT * a, int tsize, int usize){
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void insert(struct Array_ADT *a){
    int n;
    for(int i=0; i <= a->used_size; i++){
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
}

void show(struct Array_ADT *a){
    for(int i=0; i <= a->used_size; i++){
        printf("Element : %d\n", (a->ptr)[i]);
    }
}

int main(){
    struct Array_ADT arr;
    create_array(&arr, 10, 2);
    insert(&arr);
    show(&arr);
}