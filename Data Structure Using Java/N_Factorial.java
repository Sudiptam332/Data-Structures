import java.util.*;
public class N_Factorial {
    public static void main(String arg[]){
        System.out.println("Enter the Number : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int fact = factorial(n);
        System.out.println("Factorial of "+n+" : "+fact);
    }
    public static int factorial(int n){
        int f = 1;
        for(int i=1; i<=n; i++){
            f = f*i;
        }
        return f;
    }
}
