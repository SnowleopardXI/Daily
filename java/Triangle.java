class Triangle {
    double a, b, c;
    double C, area;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    double area() {
        double s = (a + b + c) / 2;
        area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }
    double C() {
        C = a + b + c;
        return C;
    }
    public static void main(String[] args) {
        Triangle t = new Triangle(3, 4, 5);
        System.out.println("Area: " + t.area());
        System.out.println("Circumference: " + t.C());
    }
}