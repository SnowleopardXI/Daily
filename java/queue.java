import java.util.*;

public class queue {
    public static void main(String[] args) {
        System.out.println("Main thread starts");
        Thread thread1 = new Thread(new User1());
        Thread thread2 = new Thread(new User2());
        Thread thread3 = new Thread(new User3());
        Thread thread4 = new Thread(new User4());
        Thread thread5 = new Thread(new User5());
        try {
            thread1.start();
            thread1.join();
            thread2.start();
            thread2.join();
            thread3.start();
            thread3.join();
            thread4.start();
            thread4.join();
            thread5.start();
            thread5.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Success");
    }
}

class User1 implements Runnable {

    @Override
    public void run() {
        System.out.println("User1 starts queuing .");
        System.out.println("queuing ...");
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("User1 finished queuing .");
    }
}

class User2 implements Runnable {

    @Override
    public void run() {
        System.out.println("User2 starts queuing .");
        System.out.println("queuing ...");
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("User2 finished queuing .");
    }
}

class User3 implements Runnable {

    @Override
    public void run() {
        System.out.println("User3 starts queuing .");
        System.out.println("queuing ...");
        try {
            Thread.sleep(300);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("User3 finished queuing .");
    }
}

class User4 implements Runnable {

    @Override
    public void run() {
        System.out.println("User4 starts queuing .");
        System.out.println("queuing ...");
        try {
            Thread.sleep(600);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("User4 finished queuing .");
    }
}

class User5 implements Runnable {

    @Override
    public void run() {
        System.out.println("User5 starts queuing .");
        System.out.println("queuing ...");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("User5 finished queuing .");
    }
}