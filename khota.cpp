#include <iostream>
#include <vector>
#include <string>

/* Defining Book class to manage book objects */
class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

public:
    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author), isIssued(false) {}

    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool getIsIssued() const { return isIssued; }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            std::cout << "Book issued successfully.\n";
        } else {
            std::cout << "Book is already issued.\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            std::cout << "Book returned successfully.\n";
        } else {
            std::cout << "Book was not issued.\n";
        }
    }

    void displayBook() const {
        std::cout << "ID: " << id << ", Title: " << title
                  << ", Author: " << author
                  << ", Status: " << (isIssued ? "Issued" : "Available") << '\n';
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Book added successfully.\n";
    }

    void displayBooks() const {
        if (books.empty()) {
            std::cout << "No books in the library.\n";
            return;
        }
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                book.issueBook();
                return;
            }
        }
        std::cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                book.returnBook();
                return;
            }
        }
        std::cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library library;
    int choice, id;
    std::string title, author;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Issue Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter Book Title: ";
            std::getline(std::cin, title);
            std::cout << "Enter Book Author: ";
            std::getline(std::cin, author);
            library.addBook(Book(id, title, author));
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            std::cout << "Enter Book ID to issue: ";
            std::cin >> id;
            library.issueBook(id);
            break;
        case 4:
            std::cout << "Enter Book ID to return: ";
            std::cin >> id;
            library.returnBook(id);
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}