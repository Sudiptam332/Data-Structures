import java.util.*;
public class Prime_OrNot {
    public static void main (String arg[]){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        boolean value = false;

        for(int i=2; i<number; i++){
            if(number % i == 0){
                value = true;
                break;
            }
        }
        if(value == true){
            System.out.println("Prime");
        }
        else{
            System.out.println("Not Prime");
        }
    }
}
