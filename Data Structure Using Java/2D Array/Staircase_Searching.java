public class Staircase_Searching {
    public static boolean Staircase_Searching(int arr[][], int find){
        int row = 0, col = arr[0].length-1;
        while(row <= arr.length-1 && col >= 0){
            if(arr[row][col] == find){
                System.out.println(row + "," + col);
                return true;
            }
            else if(arr[row][col] > find){
                col--;
            }
            else{
                row++;
            }
        }
        System.out.println("Not Find");
        return false;
    }
    public static void main(String arg[]){
        int arr[][]={{10,20,30,40},
                    {15,25,35,45},
                    {27,29,37,48},
                    {32,33,39,50}};
    int find = 33;
    Staircase_Searching(arr, find);
    }
}
