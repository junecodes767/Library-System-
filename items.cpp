#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class: Item
class Item {
protected:
    string id;
    string title;
    string type;  // Can be "Book", "CD", "DVD"
    bool isAvailable;

public:
    // Constructor
    Item(string id, string title, string type, bool isAvailable = true)
        : id(id), title(title), type(type), isAvailable(isAvailable) {
    }

    // Pure virtual function to display item details
    virtual void displayDetails() const = 0;

    // Getters and Setters
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getType() const { return type; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) { isAvailable = status; }

    // Virtual destructor
    virtual ~Item() {}
};

// Derived Class: Book
class Book : public Item {
private:
    string author;
    string genre;

public:
    // Constructor
    Book(string id, string title, string author, string genre)
        : Item(id, title, "Book"), author(author), genre(genre) {
    }

    // Override displayDetails
    void displayDetails() const override {
        cout << "Book ID: " << id << "\nTitle: " << title
            << "\nAuthor: " << author << "\nGenre: " << genre
            << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Derived Class: CD
class CD : public Item {
private:
    string artist;
    string genre;
    int runtime;  // in minutes

public:
    // Constructor
    CD(string id, string title, string artist, string genre, int runtime)
        : Item(id, title, "CD"), artist(artist), genre(genre), runtime(runtime) {
    }

    // Override displayDetails
    void displayDetails() const override {
        cout << "CD ID: " << id << "\nTitle: " << title
            << "\nArtist: " << artist << "\nGenre: " << genre
            << "\nRuntime: " << runtime << " minutes"
            << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Derived Class: DVD
class DVD : public Item {
private:
    string director;
    int runtime;  // in minutes

public:
    // Constructor
    DVD(string id, string title, string director, int runtime)
        : Item(id, title, "DVD"), director(director), runtime(runtime) {
    }

    // Override displayDetails
    void displayDetails() const override {
        cout << "DVD ID: " << id << "\nTitle: " << title
            << "\nDirector: " << director << "\nRuntime: " << runtime
            << " minutes\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
    }
};
