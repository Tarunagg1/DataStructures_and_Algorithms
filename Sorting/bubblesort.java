import java.util.Scanner;

class bubblesort {
    public static void printArr(int arr[], int a) {
        for (int i = 0; i < a; i++) {
            System.out.print(arr[i]);
        }
        System.out.println("");
    }

    public static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void bubbleSort(int arr[], int a) {
        for (int i = 0; i < a - 1; i++) {
            for (int j = 0; j < a - i - 1; j++) {
                if (arr[j + 1] < arr[j]) {
                    swap(arr, j + 1, j);
                }
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

        printArr(arr, a);
        bubbleSort(arr, a);
        printArr(arr, a);

        sc.close();
    }
}
