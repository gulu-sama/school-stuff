abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    public double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    //@Override
    double area() {
        return Math.PI * radius * radius;  
    }
}

class Rectangle extends Shape {
    public double length;
    public double width;
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    //@Override
    double area() {
        return length * width;  
    }
}

public class Main {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);  
        Shape rectangle = new Rectangle(4.0, 6.0);  

        System.out.println("Area of Circle: " + circle.area());
        System.out.println("Area of Rectangle: " + rectangle.area());
    }
}
