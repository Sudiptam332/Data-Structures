import java.util.ArrayList;
public class Container_with_Most_Water{

    public static int storeWater(ArrayList<Integer> ht){   // TC = O(n)
        int maxWater = 0;
        int lt = 0;
        int rt = ht.size()-1;

        while(lt < rt){
            int hight = Math.min(ht.get(lt), ht.get(rt));
            int width = rt-lt;
            int contain_Water = hight * width;
            maxWater = Math.max(maxWater, contain_Water);
            
            if(ht.get(lt) < ht.get(rt)){
                lt++;
            } else{
                rt--;
            }
        }

        return maxWater;

    }

    public static void main(String args[]){
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(8);
        list.add(6);
        list.add(2);
        list.add(5);
        list.add(4);
        list.add(8);
        list.add(3);
        list.add(7);

        System.out.println(storeWater(list));
    }
}