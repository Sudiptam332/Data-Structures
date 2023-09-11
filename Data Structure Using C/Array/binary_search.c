#include<stdio.h>

int binary_search(int arr[], int size, int find){
    int low, mid, high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low+high)/2;
        if(find == arr[mid]){
            return mid;
        }
        else if(find > arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[10]={2, 5, 8, 9, 45, 54, 68, 89, 93, 108};
    int size = 10;
    int find = 45;
    int index = binary_search(arr, size, find);
    printf("index : %d", index);
}