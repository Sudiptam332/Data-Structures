package Recursion;

public class Last_Occuarence {
    public static int Last_Occ(int a[], int idx, int i){
        if(i == a.length){
            return -1;
        }
        int found = Last_Occ(a, idx, i+1);

        if( found == -1 && a[i] == idx){
            return i;
        }
        return found;
    }
    public static void main(String args[]){
        int a[] = {7, 8, 9, 8, 5, 2, 3, 4};
        System.out.println(Last_Occ(a, 8, 0));
    }
}
