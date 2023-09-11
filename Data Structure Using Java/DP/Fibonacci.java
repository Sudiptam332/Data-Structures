public class Fibonacci{
    
    public static int fib_Brutforce(int n){
        if( n == 0 || n == 1 ){
            return n;
        }
        return fib_Brutforce(n-1) + fib_Brutforce(n-2);
    }

    public static int fib_Memoizetion(int dp[], int n){
        if( n == 0 || n == 1 ){
            return n;
        }
        if(dp[n] != 0){
            return dp[n];
        }
        dp[n] = fib_Memoizetion(dp, n-1) + fib_Memoizetion(dp, n-2);
        return dp[n];
    }

    public static int fib_Tabulation(int n){
        int dp[] = new int[n+1];

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    public static void main(String args[]){
        int num = 5;
        int dp[] = new int[num+1];
        System.out.println(fib_Brutforce(num));
        System.out.println(fib_Memoizetion(dp, num));
        System.out.println(fib_Tabulation(num));
    }
}