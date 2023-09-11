import java.util.*;
public class Switch {
    public static void main (String arg[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        char oparetor = sc.next().charAt(0);

        switch(oparetor){
            case '+' : System.out.println(a+b);
                break;
            case '-' : System.out.println(a-b);
                break;
            case '*' : System.out.println(a*b);
                break;
            case '/' : System.out.println(a/b);
                break;
            default : System.out.print("Wrong oparetor");
        }
    }
}
