
/*A professor calls out student IDs of students one by one while marking attendance. He 
notices that the number of students recorded in the attendance sheet is far more than 
the number of students who are actually present in the classes.

Hence, he decides to use a chitti the robot which can record the students' voices and 
keep track of which students have responded to attendance calls.

At the end of each session, the robot outputs the student IDs of the students who have 
responded to attendance calls. With this information, the professor needs your help to 
find out which students were absent.

write a program which takes an integer array a denoting the student IDs recorded by the 
robot and print the list of student IDs of the students which were 
absent in increasing order.


Input Format

The first line of input contains a single integer n denoting the number of students. 
The second line contains n space-separated integers a1,a2....an denoting the 
student IDs recorded by the robot. The students have IDs from 1 to n, inclusive.

Constraints

*1<=n<=100

1<=ai<=n*

Output Format

Print a single line containing the student IDs of the students which were absent, 
space-separated and in increasing order.

Sample:
input=
10
1 2 2 3 4 5 2 8 9 10
output=
6 7 

*/
import java.util.*;

public class Test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[sc.nextInt()] = 1;
        }

        String sep = "";
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                System.out.print(sep + i);
                sep = " ";
            }
        }
    }
}
