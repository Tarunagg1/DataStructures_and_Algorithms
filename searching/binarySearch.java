import java.util.Scanner;

public class binarySearch {

    public static int binarySearch(int arr[], int val) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == val) {
                return mid;
            } else if (val > arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number");
        int a = sc.nextInt();
        System.out.println("Enter " + a + " values");
        int arr[] = new int[a];

        for (int i = 0; i < a; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter fiinding number");
        int val = sc.nextInt();

        if (binarySearch(arr, val) != -1) {
            System.out.println("Number found");
        } else {
            System.out.println("Number not found");
        }
    }

}