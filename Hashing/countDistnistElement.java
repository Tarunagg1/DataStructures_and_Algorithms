
import java.util.HashSet;
import java.util.Scanner;

public class countDistnistElement {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number");
        int a = sc.nextInt();
        System.out.println("Enter " + a + " values");
        int arr[] = new int[a];

        for (int i = 0; i < a; i++) {
            arr[i] = sc.nextInt();
        }

        HashSet<Integer> set = new HashSet<Integer>();

        for (int ele : arr) {
            set.add(ele);
        }

        System.out.println("Count is " + set.size());
        sc.close();
    }
}
