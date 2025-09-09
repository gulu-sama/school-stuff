import java.util.Scanner;

abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    double area() {
        return Math.PI * radius * radius;  
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    @Override
    double area() {
        return length * width; 
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter shape type (circle/rectangle): ");
        String shapeType = sc.nextLine().toLowerCase(); 

        Shape shape = null;

        if (shapeType.equals("circle")) {
            
            System.out.print("Enter the radius of the circle: ");
            double radius = sc.nextDouble();
            shape = new Circle(radius); 
        } else if (shapeType.equals("rectangle")) {
           
            System.out.print("Enter the length of the rectangle: ");
            double length = sc.nextDouble();
            System.out.print("Enter the width of the rectangle: ");
            double width = sc.nextDouble();
            shape = new Rectangle(length, width); 
        } else {
            System.out.println("Invalid shape type entered.");
        }

        // check if shape is not null and print the area
        if (shape != null) {
            System.out.println("Area of the " + shapeType + ": " + shape.area());
        }

        sc.close();
    }
}
