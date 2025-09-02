interface Engine
{
    void startEngine();
    void stopEngine();
}
interface Vehicle
{
    void drive();
    void brake();
}
class Car1 implements Engine, Vehicle
{
    public void startEngine()
    {
        System.out.println("\tThe Car's engine has started\t");
    }
    public void stopEngine()
    {
        System.out.println("\tThe Car's engine has stopped");
    }

    public void drive()
    {
        System.out.println("\tThe Car has started to drive\t");
    }
    public void brake()
    {
        System.out.println("\tThe Car has stopped driving\t");
    }
}
public class car
{
    public static void main(String[] args)
    {
        Car1 C1 = new Car1();
        C1.startEngine();
        C1.stopEngine();
        C1.drive();
        C1.brake();
    }
}