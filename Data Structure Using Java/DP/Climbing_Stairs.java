public class Climbing_Stairs {
    public static int cbs_Memoizetion(int dp[], int n){
        if( n == 0 || n == 1 ){
            return 1;
        }
        if(dp[n] != 0){
            return dp[n];
        }
        dp[n] = cbs_Memoizetion(dp, n-1) + cbs_Memoizetion(dp, n-2);
        return dp[n];
    }

    public static int cbs_Tabulation(int n){
        int dp[] = new int[n+1];

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    public static void main(String args[]){
        int num = 5;
        int dp[] = new int[num+1];
        System.out.println(cbs_Memoizetion(dp, num));
        System.out.println(cbs_Tabulation(num));
    }
}
