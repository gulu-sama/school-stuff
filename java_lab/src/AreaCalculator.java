public class AreaCalculator {
    public double area(double radius) {
        return Math.PI * radius * radius;
    }

    public double area(double length, double breadth) {
        return length * breadth;
    }


    public double area(double base, double height, boolean isTriangle) {
        return 0.5 * base * height;
    }

    public static void main(String[] args) {
        AreaCalculator calc = new AreaCalculator();

        double circleArea = calc.area(7);
        double rectangleArea = calc.area(5, 10);
        double triangleArea = calc.area(6, 8, true);

        System.out.println("Area of Circle: " + circleArea);
        System.out.println("Area of Rectangle: " + rectangleArea);
        System.out.println("Area of Triangle: " + triangleArea);
    }
}
