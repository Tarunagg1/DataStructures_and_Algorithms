import java.util.Scanner;

public class insertationSort {
    public static void printArr(int arr[], int a) {
        for (int i = 0; i < a; i++) {
            System.out.print(arr[i]);
        }
        System.out.println("");
    }

    public static void insertationSorting(int arr[], int a) {
        for (int i = 1; i < a; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
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

        printArr(arr, a);
        insertationSorting(arr, a);
        printArr(arr, a);

        sc.close();
    }
}
