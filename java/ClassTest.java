import java.util.*;
public class ClassTest {
    public static class Test{
        int a;
        int b;
    }
    public static void main(String[] args) {
        ClassTest.Test[] lib = new Test[10];

        for(int i = 0; i < 10; i++){
            lib[i] = new Test();
            lib[i].a = i;
            lib[i].b = i+1;
        }
        for(int i = 0; i < 10; i++){
            System.out.println(lib[i].a + " " + lib[i].b);
        }
    }
}
