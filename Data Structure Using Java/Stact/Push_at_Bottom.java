import java.util.*;
public class Push_at_Bottom {
    public static void pushAtBottom(Stack<Integer> S, int data){
        if(S.isEmpty()){
            S.push(data);
            return;
        }
        int top = S.pop();
        pushAtBottom(S, 4);
        S.push(top);
    }
    public static void main(String args[]){
        Stack<Integer> S = new Stack<>();
        S.push(1);
        S.push(2);
        S.push(3);

        pushAtBottom(S, 4);

        while(!S.isEmpty()){
            System.out.println(S.peek());
            S.pop();
        }
    }
}
