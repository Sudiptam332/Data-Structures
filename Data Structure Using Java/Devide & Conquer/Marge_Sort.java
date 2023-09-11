public class Marge_Sort{
    public static void margeSort(int arr[], int si, int ei){
        if(si >= ei){
            return;
        }
        int mid = si+(ei-si)/2;

        margeSort(arr, si, mid);
        margeSort(arr, mid+1, ei);
        marge(arr, si, mid, ei);
    }

    public static void marge(int arr[], int si, int mid, int ei){
        int temp[] = new int[ei-si+1];
        int k = 0;
        int i = si;
        int j = mid+1;

        while(i <= mid && j <= ei){
            if(arr[i]<arr[j]){
                temp[k++]=arr[i++];
            } else{
                temp[k++]=arr[j++];
            }
        }

        while(i <= mid){
            temp[k++]=arr[i++];
        }

        while(j <= ei){
            temp[k++]=arr[j++];
        }

        for(i=si, k=0; k<temp.length; i++, k++){
            arr[i] = temp[k];
        }
    }

    public static void print(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String args[]){
        int arr[] = {6, 3, 9, 5, 2, 8};
        margeSort(arr, 0, arr.length-1);
        print(arr);
    }
}