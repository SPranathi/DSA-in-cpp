
/*Write a Java Program to create an abstract class named shape that contains two integers and an empty method named printArea.
Provide three classes named Rectangle, Triangle and Circle subclass that each one of the classes extends the Class Shape.
Each one of the classes contains only the method printArea() that prints the area of Shape. 
*/
import java.util.Scanner;

abstract class Shape {
    int a, b;

    abstract void area();
}

class Rectangle extends Shape {
    void area() {
        System.out.println("Area of the Rectangle=" + a * b);
    }
}

class Triangle extends Shape {
    void area() {
        double ar = 0.5 * a * b;
        System.out.println("Area of the Triangle=" + ar);
    }
}

class Circle extends Shape {
    void area() {
        double ar = 3.14 * a * a;
        System.out.println("Area of the Circle=" + ar);
    }
}

class shape {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Rectangle r = new Rectangle();
        Triangle t = new Triangle();
        Circle c = new Circle();
        System.out.println("Enter length and breadth of rectangle:");
        r.a = sc.nextInt();
        r.b = sc.nextInt();
        System.out.println("Enter the height and base of triangle:");
        t.a = sc.nextInt();
        t.b = sc.nextInt();
        System.out.println("Enter radius of circle:");
        c.a = sc.nextInt();
        r.area();
        t.area();
        c.area();
    }
}