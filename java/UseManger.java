import java.util.Scanner;

public class UseManger {
    public static class User {
        int id;
        String name;
        String sex;
        String birthday;
        String class1;
        String phone;
        String email;

        public static void operate(UseManger.User[] users, int operateNum) {
            switch (operateNum) {
                case 1:
                    System.out.println("Please enter the number of students:");
                    int num = new Scanner(System.in).nextInt();
                    for (int i = 0; i < num; i++) {
                        users[i] = new User();
                        System.out.println("length:" + users.length);
                        System.out.println("Please enter the id:");
                        users[i].id = new Scanner(System.in).nextInt();
                        /*
                         * int status = 0;
                         * do {
                         * status = 0;
                         * for (int j = 0; j < users.length; j++) {
                         * if (users[i].id == users[j].id) {
                         * System.out.println("The id has been used, please enter again:");
                         * users[i].id = new Scanner(System.in).nextInt();
                         * status = 1;
                         * }
                         * }
                         * } while (status == 1);
                         */
                        System.out.println("Please enter the name:");
                        users[i].name = new Scanner(System.in).next();
                        System.out.println("Please enter the sex:");
                        users[i].sex = new Scanner(System.in).next();
                        System.out.println("Please enter the birthday:");
                        users[i].birthday = new Scanner(System.in).next();
                        System.out.println("Please enter the class:");
                        users[i].class1 = new Scanner(System.in).next();
                        System.out.println("Please enter the phone:");
                        users[i].phone = new Scanner(System.in).next();
                        System.out.println("Please enter the email:");
                        users[i].email = new Scanner(System.in).next();
                        System.out.println("Add successfully!");
                    }
                    break;
                case 2:
                    System.out.println("Please enter the id of student to be deleted:");
                    int id = new Scanner(System.in).nextInt();
                    int j = 0;
                    users[j] = new User();
                    for (j = 0; j < users.length; j++) {
                        if (users[j].id == id) {
                            users[j] = null;
                        }
                    }
                    System.out.println("Delete successfully!");
                    break;
                case 3:
                    System.out.println("Please enter the id of student to be modified:");
                    int k = 0;
                    users[k] = new User();
                    int id1 = new Scanner(System.in).nextInt();
                    for (k = 0; k < users.length; k++) {
                        if (users[k].id == id1) {
                            System.out.println("Please enter the name:");
                            users[k].name = new Scanner(System.in).next();
                            System.out.println("Please enter the sex:");
                            users[k].sex = new Scanner(System.in).next();
                            System.out.println("Please enter the birthday:");
                            users[k].birthday = new Scanner(System.in).next();
                            System.out.println("Please enter the class:");
                            users[k].class1 = new Scanner(System.in).next();
                            System.out.println("Please enter the phone:");
                            users[k].phone = new Scanner(System.in).next();
                            System.out.println("Please enter the email:");
                            users[k].email = new Scanner(System.in).next();
                            System.out.println("Modify successfully!");
                        }
                    }
                    break;
                case 4:
                    System.out.println("Please enter the id of student to be searched:");
                    int id2 = new Scanner(System.in).nextInt();
                    int h = 0;
                    users[h] = new User();
                    for (h = 0; h < users.length; h++) {
                        if (users[h].id == id2) {
                            System.out.println("id:" + users[h].id);
                            System.out.println("name:" + users[h].name);
                            System.out.println("sex:" + users[h].sex);
                            System.out.println("birthday:" + users[h].birthday);
                            System.out.println("class:" + users[h].class1);
                            System.out.println("phone:" + users[h].phone);
                            System.out.println("email:" + users[h].email);
                        }
                    }
                    break;
                case 5:
                    System.exit(0);
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        User[] users = new User[50];
        int choice = 0;
        do {
            System.out.println("  Contact Management System");
            System.out.println("===========");
            System.out.println("1.Add");
            System.out.println("2.Delete");
            System.out.println("3.Modify");
            System.out.println("4.Search");
            System.out.println("5.Exit");
            System.out.println("===========");
            System.out.println("Please enter your choice:");
            choice = sc.nextInt();
            User.operate(users, choice);
        } while (choice != 5);

    }
}
