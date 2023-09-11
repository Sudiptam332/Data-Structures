public class StringCompress {
    public static void compress(String str){
        StringBuilder sb = new StringBuilder("");

        for(int i=1; i<str.length(); i++){
            sb.append(str.charAt(i-1));
            Integer count = 1;
            while(i<str.length() && str.charAt(i-1) == str.charAt(i)){
                count = count + 1;
                i++;
            }
            sb.append(count.toString());
            
        }

        System.out.print(sb);
    }
    public static void main(String args[]){
        String str = "aaaabbbcc";
        compress(str);
    }
}
