import java.util.*;

public class Employee {
    String name;
    int id;
    int age;
    double salary;

    public Employee(String name, int id, int age, double salary) {
        this.name = name;
        this.id = id;
        this.age = age;
        this.salary = salary;
    }

    public static double average(Employee[] emp) {
        double avg = 0;
        int i;
        for (i = 0; i < emp.length; i++) {
            avg += emp[i].salary;
        }
        return avg / emp.length;
    }



    public static void main(String args[]) {
        try (Scanner Obj = new Scanner(System.in)) {
            System.out.println("Enter the number of employees");
            int n = Obj.nextInt();
            Employee[] emp = new Employee[n];
            for (int i = 0; i < n; i++) {
                System.out.printf("Enter the name of the %d employee: ", i + 1);
                String name = Obj.next();
                System.out.printf("Enter the id of the %d employee: ", i + 1);
                int id = Obj.nextInt();
                System.out.printf("Enter the age of the %d employee: ", i + 1);
                int age = Obj.nextInt();
                System.out.printf("Enter the salary of the %d employee: ", i + 1);
                double salary = Obj.nextDouble();
                emp[i] = new Employee(name, id, age, salary);
            }
            System.out.printf("Average salary of the employees is %f\n", average(emp));
        }
    }
}