public class Daigonal_Sum {

    public static int Daigonal_Sum(int arr[][], int max_row, int max_col){
        int sum = 0;
        int size = arr.length;
        for(int i=0; i<size; i++){
            sum += arr[i][i];

            if(i != size-1-i){
                sum += arr[i][size-1-i];
            }
        }
        return sum;
    }
    public static void main(String arg[]){
        int arr[][]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};

        int sum = Daigonal_Sum(arr, 4, 4);
        System.out.println(sum);
    }
}
