class Account
{
    double balance;
    public Account(double balance)
    {
        this.balance = balance;
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        }
        else
        {
            System.out.println("Insufficient balance");
        }
    }
    void displayBalance()
    {
        System.out.println("Balance: " + balance);
    }
}
class SavingsAccount extends Account
{
    final double MIN_BALANCE= 500;
    public SavingsAccount(double balance)
    {
        super(balance);
    }
    void withdraw(double amount)
    {
        if ((balance - amount) >= MIN_BALANCE)
        {
            balance -= amount;
            System.out.println("SavingsAcc Withdrawn: " + amount);
        }
        else
        {
            System.out.println("Cannot withdraw.");
        }
    }
}
class CurrentAccount extends Account
{
    public CurrentAccount(double balance)
    {
        super(balance);
    }
    void withdraw(double amount)
    {
        balance -= amount;
        System.out.println("CurrentAccount Withdrawn: " + amount);
    }


}
public class bankacc
{
    public static void main(String[] args)
    {
        System.out.println(" Savings Account ");
        SavingsAccount sa = new SavingsAccount(1000);
        sa.displayBalance();
        sa.withdraw(400);
        sa.displayBalance();
        sa.withdraw(200);
        sa.displayBalance();

        System.out.println("\n Current Account ");
        CurrentAccount ca = new CurrentAccount(500);
        ca.displayBalance();
        ca.withdraw(1200);
        ca.displayBalance();
        ca.withdraw(500);
        ca.displayBalance();
    }
}

