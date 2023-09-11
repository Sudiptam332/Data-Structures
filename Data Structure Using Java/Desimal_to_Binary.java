import java.util.Scanner;

public class Desimal_to_Binary {

    public static void D_to_B(int d_num){
        int pow = 0;
        int b_number = 0;
        while(d_num > 0){
            int lastdigt = d_num % 2;
            b_number = b_number + (lastdigt * (int)Math.pow(10, pow));
            pow++;
            d_num = d_num / 2;
        }
        System.out.println(b_number);
    }
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int d_num = sc.nextInt();
        D_to_B(d_num);
    }
}
