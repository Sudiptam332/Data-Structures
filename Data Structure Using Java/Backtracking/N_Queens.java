import java.util.*;
public class N_Queens{
    public static boolean isSafe(char board[][], int row, int col){
        // top
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i=row-1, j=col+1; i>=0 && j<board[0].length; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    public static void possible_Soloution(char board[][], int row){
        if(row == board.length){
            printSol(board);
            return;
        }
        for(int i=0; i<board.length; i++){
            if(isSafe(board, row, i)){
                board[row][i] = 'Q';
                possible_Soloution(board, row+1);
                board[row][i] = 'X';
            }
        }
    }

    public static void printSol(char board[][]){
        System.out.println("---------- Chess Board ----------");
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                System.out.print(board[i][j] + " ");;
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the value of N : ");
        int n = sc.nextInt();
        char board[][] = new char[n][n];

        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                board[i][j] = 'X';
            }
        }

        possible_Soloution(board, 0);
    }
}