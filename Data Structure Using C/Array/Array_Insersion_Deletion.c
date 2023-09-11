#include<stdio.h>

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int index, int size, int t_size, int ele){
    if(index > t_size){
        return -1;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=ele;
    return 1;
}

void delete(int arr[], int index, int size){
    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[100]={2, 4, 9, 12, 50};
    int size = 5;
    display(arr, size);

    int index = 3;
    int ele = 10;
    insert(arr, index, size, 100, ele);
    size += 1;
    display(arr, size);

    int d_index = 2;
    delete(arr, d_index, size);
    size -= 1;
    display(arr, size);
}