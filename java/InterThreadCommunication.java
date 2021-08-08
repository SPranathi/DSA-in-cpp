/*
Write a Java program that correctly implements producer 
consumer problem using the concept of inter thread communication.
*/
class Buffer {
    int a;
    boolean produced = false;

    public synchronized void produce(int x) {
        a = x;
        System.out.println("Product " + a + " is Produced.");
        produced = true;
        notify();
        if (produced != false) {
            System.out.println("Producer is waiting...");
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }

    public synchronized void consume() {
        if (!produced) {
            System.out.println("Consumer is waiting...");
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        System.out.println("Product " + a + " is consumed.");
        produced = false;
        notify();
    }
}

class Producer extends Thread {
    Buffer b;

    public Producer(Buffer b) {
        this.b = b;
    }

    public void run() {
        System.out.println("Product start synchronized producing...");
        for (int i = 1; i <= 10; i++) {
            b.produce(i);
        }
    }
}

class Consumer extends Thread {
    Buffer b;

    public Consumer(Buffer b) {
        this.b = b;
    }

    public void run() {
        System.out.println("Consumer start synchronized consuming...");
        for (int i = 1; i <= 10; i++) {
            b.consume();
        }
    }
}

public class InterThreadCommunication {
    public static void main(String args[]) {
        // create buffer object
        Buffer b = new Buffer();
        // creating producer thread
        Producer p = new Producer(b);
        // creating consumer thread
        Consumer c = new Consumer(b);
        // starting threads.
        p.start();
        c.start();
    }
}