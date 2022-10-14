import java.util.Scanner;

public class RationalCalc {
    public class Rational {
        private int numerator;
        private int denominator;

        public Rational(int numerator, int denominator) {
            this.numerator = numerator;
            this.denominator = denominator;
        }

        public Rational add(Rational r) {
            int numerator = this.numerator * r.denominator + this.denominator * r.numerator;
            int denominator = this.denominator * r.denominator;
            return new Rational(numerator, denominator);
        }

        public Rational sub(Rational r) {
            int numerator = this.numerator * r.denominator - this.denominator * r.numerator;
            int denominator = this.denominator * r.denominator;
            return new Rational(numerator, denominator);
        }

        public Rational mul(Rational r) {
            int numerator = this.numerator * r.numerator;
            int denominator = this.denominator * r.denominator;
            return new Rational(numerator, denominator);
        }

        public Rational div(Rational r) {
            int numerator = this.numerator * r.denominator;
            int denominator = this.denominator * r.numerator;
            return new Rational(numerator, denominator);
        }

        public String toString() {
            return numerator + "/" + denominator;
        }
    }

    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            // 判断分母是否为0
            while (true) {
                System.out.println("请输入第一个分数的分子和分母：");
                int numerator1 = input.nextInt();
                int denominator1 = input.nextInt();
                if (denominator1 == 0) {
                    System.out.println("分母不能为0，请重新输入！");
                    continue;
                }
                System.out.println("请输入第二个分数的分子和分母：");
                int numerator2 = input.nextInt();
                int denominator2 = input.nextInt();
                if (denominator2 == 0) {
                    System.out.println("分母不能为0，请重新输入！");
                    continue;
                }
                RationalCalc myJava = new RationalCalc();
                RationalCalc.Rational rational1 = myJava.new Rational(numerator1, denominator1);
                RationalCalc.Rational rational2 = myJava.new Rational(numerator2, denominator2);
                // 有理数r1与r2的和
                Rational rational3 = rational1.add(rational2);
                // 有理数r1与r2的差
                Rational rational4 = rational1.sub(rational2);
                // 有理数r1与r2的积
                Rational rational5 = rational1.mul(rational2);
                // 有理数r1与r2的商
                Rational rational6 = rational1.div(rational2);
                System.out.println("有理数" + rational1 + " 与有理数 " + rational2 + " 的和为 " + rational3);
                System.out.println("有理数" + rational1 + " 与有理数 " + rational2 + " 的差为 " + rational4);
                System.out.println("有理数" + rational1 + " 与有理数 " + rational2 + " 的积为 " + rational5);
                System.out.println("有理数" + rational1 + " 与有理数 " + rational2 + " 的商为 " + rational6);
                break;
            }
        }
    }
}