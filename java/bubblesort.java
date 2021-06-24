import java.util.*;

class bubblesort {
    static void Bubblesort(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            boolean swap = false; // keeping the track of swapping
            // loop for compare elements
            for (int j = 0; j < n - i - 1; j++) {
                // compare adjacent elements
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    // if swapping occurs set swap to true
                    swap = true;
                }
            }
            // no swap means array is sorted
            if (swap == false)
                break;
        }

    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = in.nextInt();
        System.out.println("Enter the elements of the array:");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        bubblesort.Bubblesort(arr, n);
        System.out.println("Sorted array in Ascending order using BubbleSort:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
