package Recursion;

public class Fibonacci {
    public static int fibo(int n){
        if(n == 0){
            return 0;
        } else if(n == 1){
            return 1;
        } 
        int curr_fibo = fibo(n-2) + fibo(n-1);
        return curr_fibo;
    }
    public static void main(String args[]){
        for(int i=0; i<=4; i++){
            System.out.print(fibo(i) + " ");
        }
    }
}
