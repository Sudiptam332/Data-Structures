public class Knapsack {
    
    public static int knapsack_Brut(int val[], int wt[], int w, int i){
        if(i == 0 || w == 0){
            return 0;
        }

        if(wt[i] <= w){
            //include
            int res1 = val[i] + knapsack_Brut(val, wt, w-wt[i], i-1);
            //exclude
            int res2 = knapsack_Brut(val, wt, w, i-1);

            return Math.max(res1, res2);
        }

        return knapsack_Brut(val, wt, w, i-1);
    }

    public static int knapsack_Memo(int val[], int wt[], int w, int i, int dp[][]){
        if(i == 0 || w == 0){
            return 0;
        }
        
        if(dp[i][w] != 0){
            return dp[i][w];
        }

        if(wt[i-1] <= w){
            //include
            int res1 = val[i-1] + knapsack_Memo(val, wt, w-wt[i-1], i-1, dp);
            //exclude
            int res2 = knapsack_Memo(val, wt, w, i-1, dp);
            dp[i][w] = Math.max(res1, res2);
            return dp[i][w];

        }
        
        dp[i][w] = knapsack_Memo(val, wt, w, i-1, dp);
        return dp[i][w];
    }
    public static void main(String args[]){
        int val[] = {15, 14, 10, 45, 30};
        int wt[] = {2, 5, 1, 3, 4};
        int w = 7;
        int dp[][] = new int[val.length+1][w+1];

        System.out.println(knapsack_Brut(val, wt, w, val.length-1));
        System.out.println(knapsack_Memo(val, wt, w, val.length, dp));
    }
}
