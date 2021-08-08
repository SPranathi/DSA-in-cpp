import java.util.*;

public class DeleteDLL {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> dll = new LinkedList<Integer>();
        System.out.print("Enter size of Linked list: ");
        int n = sc.nextInt();
        System.out.println("Enter values:");
        for (int i = 0; i < n; i++)
            dll.add(sc.nextInt());
        System.out.print("Enter the elements to be deleted:");
        Integer ele = sc.nextInt();
        if (dll.contains(ele)) {
            dll.remove(ele);
            System.out.println("Elements after deleting:" + ele);
        } else
            System.out.println("Element not found");
        System.out.println(dll);
    }
}
