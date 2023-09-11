import java.util.ArrayList;

public class Stack_Using_ArrayList{
    static class Stack{
        static ArrayList<Integer> list = new ArrayList<>();

        public static boolean isEmpty(){
            return list.size() == 0;
        }

        //push
        public static void push(int data){
            list.add(data);
        }
        //pop
        public static int pop(){
            if(isEmpty()){
                return -1;
            }
            int top = list.get(list.size()-1);
            list.remove(list.size()-1);
            return top;
        }
        //peek
        public static int peek(){
            if(isEmpty()){
                return -1;
            }
            return list.get(list.size()-1);
        }
    }
    public static void main(String args[]){
        Stack S = new Stack();
        S.push(1);
        S.push(2);
        S.push(3);

        while(!S.isEmpty()){
            System.out.println(S.peek());
            S.pop();
        }
    }
}