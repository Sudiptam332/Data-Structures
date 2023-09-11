import java.util.*;
public class Reverse_Number {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        while(number > 0) {
            System.out.print(number % 10);
            number = number / 10;
        }
    }
}
