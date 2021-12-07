#include <iostream>
#include <string.h>

using namespace std;

class Book
{
    private:
        char* title;
        const long long ISBN;
        double price;
        char* copyArray(char* target, char* source){
            int size =  strlen(source);
            target = new char[size+1];
            for (int i = 0; i < size; i++)
                target[i] = source[i];
            target[size] = '\0';
            return target;
        }
        // char* copyArray(char* target, const char* source){
        //     int size =  strlen(source);
        //     target = new char[size+1];
        //     for (int i = 0; i < size; i++)
        //         target[i] = source[i];
        //     target[size] = '\0';
        //     return target;
        // }
    public:
    // Default constructor
    Book() : ISBN(0) 
    {
        title = nullptr;
        price = 0.0;
    }
    // Constructor
    Book(char* _title, long long _ISBN, double _price) : ISBN(_ISBN)
    {
        title = nullptr;
        setTitle(_title);
        setPrice(_price);   
    }
    // Copy constructor
    Book(const Book& book) : ISBN(book.ISBN)
    {
        title = copyArray(title, book.title);
        price = book.price;
    }
    // Destructor
    ~Book()
    {
        if (title != nullptr)
            delete[] title;
    }
    // setter for title
    void setTitle(char* _title)
    {
        delete[] title;
        title = copyArray(title, _title);
    }
    // setter for price
    void setPrice(double _price)
    {
        price = _price < 0 ? 0 : _price;
    }
    // getter for title
    char* getTitle() const
    {
        if (title == nullptr)
            return "No Title";
        int size = strlen(title);
        char* temp = new char[size+1];
        for (int i = 0; i < size; i++)
            temp[i] = title[i];
        temp[size] = '\0';
        return temp;
    }
    // getter for price
    double getPrice() const
    {
        return price;
    }
    // getter for ISBN
    long long getISBN() const
    {
        long long temp = ISBN;
        return temp;
    }
    //---------------------------------------------------------- OPERATOR OVERLOADING ---------------------------------------------------------- //
    // overloaded assignment operator
    Book& operator=(const Book& other)
    {
        if (this != &other)
        {
            // this->ISBN = other.ISBN;
            delete[] title;
            title = copyArray(title, other.title);
            price = other.price;
        }
        return *this;
    }
    // overloaded equality operator
    bool operator==(const Book& other) const
    {
        return (ISBN == other.ISBN);
    }
    // overloaded inequality operator
    bool operator!=(const Book& other) const
    {
        return (ISBN != other.ISBN);
    }
    // ---------------------------------------------------------- END OF OPERATOR OVERLOADING ---------------------------------------------------------- //
};

// display function for  using istream
istream& operator>>(istream& in, Book& book)
{
    char title[100];
    double price;
    long long int ISBN;
    cout << "Enter title: ";
    in >> title;
    cout << "Enter ISBN: ";
    in >> ISBN;
    cout << "Enter price: ";
    in >> price;
    Book temp = Book(title, ISBN, price);
    book = temp;
    return in;
}
// display function for using ostream
ostream& operator<<(ostream& out,const Book& book)
{
    out << book.getISBN() << " " << book.getTitle() << " " << book.getPrice();
    return out;
}

// test function for Book class
void testBook()
{
    Book book1;
    Book book2("The C++ Programming Language", 9780136093319, 49.99);
    Book book3(book2);
    Book book4;
    book4 = book2;
    cout << "Book 1: " << book1 << endl;
    cout << "Book 2: " << book2 << endl;
    cout << "Book 3: " << book3 << endl;
    cout << "Book 4: " << book4 << endl;
    cout << "Book 1 == Book 2: " << (book1 == book2) << endl;
    cout << "Book 1 != Book 2: " << (book1 != book2) << endl;
    cout << "Book 1 == Book 3: " << (book1 == book3) << endl;
    cout << "Book 1 != Book 3: " << (book1 != book3) << endl;
    cout << "Book 2 == Book 3: " << (book2 == book3) << endl;
    cout << "Book 2 != Book 3: " << (book2 != book3) << endl;
    cout << "Book 2 == Book 4: " << (book2 == book4) << endl;
    cout << "Book 2 != Book 4: " << (book2 != book4) << endl;
    cout << "Book 3 == Book 4: " << (book3 == book4) << endl;
    cout << "Book 3 != Book 4: " << (book3 != book4) << endl;
}

// main function
int main()
{
    testBook();
    return 0;
}




