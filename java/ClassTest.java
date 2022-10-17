
import java.util.Scanner;

/**
 *
 * @author 裴宇莹
 */
public class ClassTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int m,n; 
        Scanner reader=new Scanner(System.in);
        n=reader.nextInt();
        m=reader.nextInt();
        System.out.println("最大公约数是"+gys(m,n));
        System.out.println("最小公倍数是"+gbs(m,n));
    }
    public static int gys(int m,int n){
       int t;
        do {
            t=m%n;
            m=n;
            n=t;          
        } while (t!=0);
        return m;
    }
    public static int gbs(int m,int n){
        return m*n/gys(m,n);
    }
}