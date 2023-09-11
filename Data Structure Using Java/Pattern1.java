public class Pattern1{
    public static void main (String arg[]) {
        char ch = 'A';
        int n = 4;

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                System.out.print(ch);
                ch++;
            }
            System.out.println();
        }
    }
}