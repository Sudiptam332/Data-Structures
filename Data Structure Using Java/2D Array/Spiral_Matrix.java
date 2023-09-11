public class Spiral_Matrix {

    public static void spiral_matrix(int arr[][], int max_row, int max_col){
        int sr = 0;
        int er = max_row-1;
        int sc = 0;
        int ec = max_col-1;

        while(sr<=er && sc<=ec){
            //top
            for(int i=sc; i<=ec; i++){
                System.out.print(arr[sr][i]+" ");
            }

            //right
            for(int i=sr+1; i<=er; i++){
                System.out.print(arr[i][ec]+" ");
            }

            //bottom
            for(int i=ec-1; i>=sc; i--){
                if(sc == ec){
                    break;
                }
                System.out.print(arr[er][i]+" ");
            }

            //left
            for(int i=er-1; i>=sr+1; i--){
                if(sc == ec){
                    break;
                }
                System.out.print(arr[i][sc]+" ");
            }

            sr++;
            er--;
            sc++;
            ec--;            
        }
        System.out.println();
    }

    public static void main(String arg[]){
        int arr[][]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};

        spiral_matrix(arr, 4, 4);
    }
}
