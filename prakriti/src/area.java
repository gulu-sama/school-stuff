import java.awt.Rectangle;
import java.util.Scanner;

public class area {
    public static void main(String[] args) {
        int area1;
        int area2;

        Rectangle R1 = new Rectangle();
        R1.height = 15;
        R1.width = 10;
        area1 = R1.height * R1.width;
        System.out.println("Area of Rectangle 1 is: " + area1);

        Rectangle R2 = new Rectangle();
        getData(R2);
        area2 = R2.height * R2.width;
        System.out.println("Area of Rectangle 2 is: " + area2);
    }

    public static void getData(Rectangle rect) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter height for Rectangle: ");
        rect.height = sc.nextInt();
        System.out.print("Enter width for Rectangle: ");
        rect.width = sc.nextInt();
    }
}
