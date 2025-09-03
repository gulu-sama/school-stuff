//Q. wap using interface shape to calculate area &perimeter of a circle and rect

// Define the Shape interface
interface Shape {
    double area();
    double perimeter();
}

// Implement the Circle class
class Circle implements Shape {
    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// Implement the Rectangle class
class Rectangle implements Shape {
    double length;
    double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double area() {
        return length * width;
    }

    @Override
    public double perimeter() {
        return 2 * (length + width);
    }
}


public class simple_calculator {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);
        System.out.println("Circle Area: " + circle.area());
        System.out.println("Circle Perimeter: " + circle.perimeter());

        Shape rectangle = new Rectangle(4.0, 6.0);
        System.out.println("Rectangle Area: " + rectangle.area());
        System.out.println("Rectangle Perimeter: " + rectangle.perimeter());
    }
}
