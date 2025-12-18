import java.util.Scanner;

public class LibrarySystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library library = new Library();

        while (true) {
            System.out.println("\nLibrary Menu:");
            System.out.println("1. Add Book");
            System.out.println("2. Search Book");
            System.out.println("3. Display Books");
            System.out.println("4. Exit");
            System.out.print("Select an option: ");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            switch (choice) {
                case 1: // Add Book
                    System.out.print("Enter title: ");
                    String title = sc.nextLine();
                    System.out.print("Enter author: ");
                    String author = sc.nextLine();
                    System.out.print("Enter ISBN: ");
                    String isbn = sc.nextLine();
                    library.addBook(new Book(title, author, isbn));
                    break;

                case 2: // Search Book
                    System.out.print("Enter title to search: ");
                    String searchTitle = sc.nextLine();
                    Book foundBook = library.searchBook(searchTitle);
                    if (foundBook != null) {
                        System.out.println("Book found:");
                        foundBook.display();
                    } else {
                        System.out.println("Book not found.");
                    }
                    break;

                case 3: // Display Books
                    System.out.println("Books in the Library:");
                    library.displayBooks();
                    break;

                case 4: // Exit
                    System.out.println("Exiting the system.");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
