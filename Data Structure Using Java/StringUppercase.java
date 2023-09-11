public class StringUppercase{

    public static void uppercase(String str){
        StringBuilder sb = new StringBuilder("");

        char ch = Character.toUpperCase(str.charAt(0));
        sb.append(ch);

        for(int i=1; i<str.length(); i++){
            if(str.charAt(i-1) == ' '){
                char ch2 = Character.toUpperCase(str.charAt(i));
                sb.append(ch2);
            }else{
                sb.append(str.charAt(i));
            }
        }

        System.out.print(sb);
    }
    public static void main(String args[]){
        String str = "hi, i am sudipta.";
        uppercase(str);
    }
}