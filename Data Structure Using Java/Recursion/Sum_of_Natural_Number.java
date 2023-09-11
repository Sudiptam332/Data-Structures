package Recursion;

public class Sum_of_Natural_Number {
    public static int sum(int n){
        if(n==1){
            return 1;
        }
        int T_sum = n + sum(n-1);
        return T_sum;
    }
    public static void main(String agrs[]){
        System.out.println(sum(5));
    }
}
