public class Printer {

    void print(int x) {
        System.out.println(x);
    }

    void print(double x) {
        System.out.println(x);
    }

    void print(String x) {
        System.out.println(x);
    }

    void print(char x) {
        System.out.println(x);
    }

    public static void main(String[] args) {
        Printer p = new Printer();

        p.print(10);
        p.print(3.14);
        p.print("Hello");
        p.print('A');
    }
}

