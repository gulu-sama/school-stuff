class Employee {
    String name;
    double baseSalary;

    public Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    double bonus() {
        return 0;
    }

    double monthlyPay() {
        return baseSalary;
    }

    void showDetails() {
        System.out.println("Employee: " + name);
        System.out.println("Base Salary: " + baseSalary);
        System.out.println("Bonus: " + bonus());
        System.out.println("Monthly Pay: " + monthlyPay());
    }
}


class CircleEmployee extends Employee {
    public CircleEmployee(String name, double baseSalary) {
        super(name, baseSalary);
    }

    double bonus() {
        return baseSalary * 0.10;
    }
    double monthlyPay() {
        return baseSalary + bonus();
    }
}


class RectangleEmployee extends Employee {

    public RectangleEmployee(String name, double baseSalary) {
        super(name, baseSalary);
    }
    double bonus() {
        return baseSalary * 0.15;
    }

    double monthlyPay() {
        return baseSalary + bonus();
    }
}


public class PayrollTest {
    public static void main(String[] args) {
        Employee emp1 = new CircleEmployee("oggy", 5000);
        emp1.showDetails();

        System.out.println("");


        Employee emp2 = new RectangleEmployee("ben", 6000);
        emp2.showDetails();
    }
}