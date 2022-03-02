import java.util.Scanner;

public class selectionSort {
    public static void printArr(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.println("");
    }

    public static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void selectionSorting(int arr[], int a) {
        for (int i = 0; i < a - 1; i++) {
            int min = i;
            for (int j = i + 1; j < a; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                swap(arr, min, i);
            }
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

        printArr(arr);
        selectionSorting(arr, a);
        printArr(arr);

        sc.close();
    }
}
