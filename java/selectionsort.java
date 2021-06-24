import java.util.*;

class selectionsort {
    static void Selectionsort(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = in.nextInt();
        System.out.println("Enter the elements of the arrray: ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        selectionsort.Selectionsort(arr, n);
        System.out.println("Sorted array in Ascending order by using SelectionSort:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + "  ");
        }

    }
}
