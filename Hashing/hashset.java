import java.util.HashSet;

public class hashset{
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<>();
        set.add(5);
        set.add(10);
        System.out.println(set);

        if(set.contains(10)){
            System.out.println("present");
        }else{
            System.out.println("Not present");
        }
    }
}