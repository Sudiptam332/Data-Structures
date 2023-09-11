import java.util.*;

public class Binary_to_Decimal {

    public static int B_to_D(int b_number){
        
        int pow = 0;
        int dec = 0;

        while(b_number > 0){
            int lastdigt = b_number % 10;
            dec = dec + (lastdigt * (int)Math.pow(2, pow));
            pow++;
            b_number = b_number/10;
        }
        return dec;
    }

    public static void main(String arg[]){
        System.out.println("Enter the binary Number: ");
        Scanner sc = new Scanner(System.in);
        int b_number = sc.nextInt();
        int dec = B_to_D(b_number);
        System.out.println("Decimal : "+dec);
    }
    
}
