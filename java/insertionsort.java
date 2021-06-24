import java.util.*;

class insertionsort {
    static void Insertionsort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                } else {
                    break;
                }

            }
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = in.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        insertionsort.Insertionsort(arr, n);
        System.out.println("Sorted array in Ascending order by using Insertion Sort:");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");

    }
}
