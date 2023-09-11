package Recursion;

public class First_Occuarence{
    public static int F_oucc(int a[], int idx, int i){
        if(i == a.length){
            return -1;
        }
        if(a[i] == idx){
            return i;
        }
        return F_oucc(a, idx, i+1);
    }
    public static void main(String args[]){
        int a[] = {7, 8, 9, 8, 5, 2, 3, 4};
        System.out.println(F_oucc(a, 8, 0));
    }
}