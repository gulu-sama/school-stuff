class Book {
    String bookName;
    String authorName;
    int datePublished;

    public Book(String bookName, String authorName, int datePublished) {
        this.bookName = bookName;
        this.authorName = authorName;
        this.datePublished = datePublished;
    }

    public void displayDetails() {
        System.out.println("Book Name: " + bookName);
        System.out.println("Author Name: " + authorName);
        System.out.println("Published Year: " + datePublished);
    }
}

public class library_book_management {
    public static void main(String[] args) {
        Book book1 = new Book("Billy", "Naoki Urasawa", 2008);
        book1.displayDetails();
    }
}
