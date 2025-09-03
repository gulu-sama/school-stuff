public class leapyear
{
    public static void main(String[] args){
        int a = 1999;
        if(a%400==0){
            System.out.println("1999 is leap year");
        } else if(a%4==0 && a%100!=0){
            System.out.println("1999 is leap year");
        } else {
            System.out.println("1999 is not leap year");
        }
    }
}
