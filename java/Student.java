//编写Java程序，实现学生通讯录管理功能（增、删、改、查），并完成程序的测试。
//学生通讯录内容包括学号、姓名、性别、生日、班级、手机号、E-mail地址
import java.util.*;

public class Student {
    public static class User {
        int id;
        String name;
        String sex;
        String birthday;
        String class1;
        String phone;
        String email;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            User[] users = new User[50];
            while (true) {
                System.out.println("  Contact Management System");
                System.out.println("===========");
                System.out.println("1.Add");
                System.out.println("2.Delete");
                System.out.println("3.Modify");
                System.out.println("4.Search");
                System.out.println("5.Exit");
                System.out.println("===========");
                System.out.println("Please enter your choice:");
                int choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        System.out.println("Please enter the number of students:");
                        int num = sc.nextInt();
                        for (int i = 0; i < num; i++) {
                            System.out.println("Please enter the id:");
                            users[i].id = sc.nextInt();
                            System.out.println("Please enter the name:");
                            users[i].name = sc.next();
                            System.out.println("Please enter the sex:");
                            users[i].sex = sc.next();
                            System.out.println("Please enter the birthday:");
                            users[i].birthday = sc.next();
                            System.out.println("Please enter the class:");
                            users[i].class1 = sc.next();
                            System.out.println("Please enter the phone:");
                            users[i].phone = sc.next();
                            System.out.println("Please enter the email:");
                            users[i].email = sc.next();
                        }
                        break;
                    case 2:
                        System.out.println("Please enter the id of student to be deleted:");
                        int id = sc.nextInt();
                        for (int i = 0; i < users.length; i++) {
                            if (users[i].id == id) {
                                users[i] = null;
                            }
                        }
                        break;
                    case 3:
                        System.out.println("Please enter the id of student to be modified:");
                        int id1 = sc.nextInt();
                        for (int i = 0; i < users.length; i++) {
                            if (users[i].id == id1) 
                            {
                                System.out.println("Please enter the name:");
                                users[i].name = sc.next();
                                System.out.println("Please enter sex:");
                                users[i].sex = sc.next();
                                System.out.println("Please enter the birthday:");
                                users[i].birthday = sc.next();
                                System.out.println("Please enter the class:");
                                users[i].class1 = sc.next();
                                System.out.println("Please enter the phone:");
                                users[i].phone = sc.next();
                                System.out.println("Please enter the email:");
                                users[i].email = sc.next();
                            }
                        }
                        break;
                    case 4:
                        System.out.println("Please enter the id of student to be searched:");
                        int id2 = sc.nextInt();
                        for (int i = 0; i < users.length; i++) {
                            if (users[i].id == id2) {
                                System.out.println("id:" + users[i].id);
                                System.out.println("name:" + users[i].name);
                                System.out.println("sex:" + users[i].sex);
                                System.out.println("birthday:" + users[i].birthday);
                                System.out.println("class:" + users[i].class1);
                                System.out.println("phone:" + users[i].phone);
                                System.out.println("email:" + users[i].email);
                                break;
                            }
                        }
                        break;
                    case 5:
                        System.out.println("Exit");
                        System.exit(0);
                }
            }
        }
    }
}