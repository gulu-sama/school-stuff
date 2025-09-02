public class ticketBooking
{
    public void bookTicket(String personName)
    {
        System.out.println("Booking ticket for single person: " + personName);

    }
    public void bookTicket(String[] groupNames)
    {
        System.out.println("Booking tickets for group:");
        for (String name : groupNames)
        {
            System.out.println("- " + name);
        }

    }
    public void bookTicket(String personName, String seatPref)
    {
        System.out.println("Booking ticket for " + personName + " with seat preference: " + seatPref);
    }
    public static void main(String[] args) {
        ticketBooking tb = new ticketBooking();
        tb.bookTicket("helena");
        String[] group = {"siri", "david", "royce"};
        tb.bookTicket(group);
        tb.bookTicket("tia", "Window seat");
    }
}