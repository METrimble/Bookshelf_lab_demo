#include <iostream>
using namespace std;

class bookshelf{
    private:
        string* books;
        int num_books;
        string bookshelf_name;

    public:
        bookshelf(); //constructor

        //getters & setters
        int get_num_books(); //getter
        void set_num_books(int new_num_books); //setter

        string get_bookshelf_name(); //getter
        void set_bookshelf_name(string new_name); //setter

        //Other Functions 
        void create_bookshelf(int num_books_to_create); 
        void print_bookshelf();

        //big three
        ~bookshelf(); //destructor
        bookshelf(bookshelf &other_obj); //copy constructor
        bookshelf& operator=(bookshelf & other_obj); //assignment operator overload
};