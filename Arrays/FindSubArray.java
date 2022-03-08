import java.util.HashMap;
import java.util.Scanner;

class FindSubArray {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number");
        int a = sc.nextInt();
        System.out.println("Enter " + a + " values");
        int arr[] = new int[a];

        for (int i = 0; i < a; i++) {
            arr[i] = sc.nextInt();
        }

        int sum = 10;

        int currSum = 0;
        int start = 0;
        int end = -1;

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < a; i++) {
            currSum += arr[i];

            if (currSum - sum == 0) {
                start = 0;
                end = i;
                break;
            }

            if (map.contains(currSum - sum)) {
                start = map.get(currSum - sum) + 1;
                end = i;
                break;
            }
            map.put(currSum, i);
        }

        if (end == -1) {
            System.out.println("Not found");
        } else {
            System.out.println("sound " + start + " " + end);
        }

    }
}