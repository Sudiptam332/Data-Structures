package Recursion;

public class is_Array_Sorted {
    public static boolean isSorted(int a[], int i){
        if(i == a.length-1){
            return true;
        }
        if(a[i] > a[i+1]){
            return false;
        }
        return isSorted(a, i+1);
    }
    public static void main(String args[]){
        int a[] = new int[5];
        a[0]=10;  
        a[1]=20;  
        a[2]=30;  
        a[3]=40;  
        a[4]=50;
        System.out.println(isSorted(a,0));
    }
}
