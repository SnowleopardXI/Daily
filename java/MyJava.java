
import java.util.Scanner;

public class MyJava {

    public void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            System.out.println("请输入第一个整数：");
            int n = scan.nextInt();
            System.out.println("请输入第二个整数：");
            int m = scan.nextInt();
            int x;
            if (m > n) {
                x = n;
            } else {
                x = m;
            }
            while (m % x != 0 || n % x != 0)
                x--;
            System.out.println(x);
        }
    }

}