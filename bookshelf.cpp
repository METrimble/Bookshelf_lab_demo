#include "bookshelf.h"

/******************
 * Constructor
******************/

bookshelf::bookshelf(){
    this->books = NULL;
    this->num_books = 0;
}

/*****************
 * getters & setters
*****************/

int bookshelf::get_num_books(){
    return this->num_books;
}

void bookshelf::set_num_books(int new_num_books){
    this->num_books = new_num_books;
}

string bookshelf::get_bookshelf_name(){
    return this->bookshelf_name;
}

void bookshelf::set_bookshelf_name(string new_name){
    this->bookshelf_name = new_name;
}

/*****************
 * Other Functions
*****************/

void bookshelf::create_bookshelf(int num_books_to_create){
    this->books = new string[num_books_to_create];
    this->num_books = num_books_to_create;
    cout << "Enter your bookshelf name: ";
    cin >> this->bookshelf_name;

    for(int i = 0; i < num_books_to_create; i++){
        cout << "Enter a book name: ";
        cin >> this->books[i];
        cout << "----------------------------------" << endl;
    }
    cout << endl;
}

void bookshelf::print_bookshelf(){
    cout << "Here is your bookshelf: " << this->bookshelf_name << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < this->num_books; i++){
        cout << "Book " << i << ": " << this->books[i] << endl;
    }
    cout << endl;
}

/******************
 * Big Three:
 * 
 * Differences between AOO and CC:
 * both perform deep copies
 * CC is used when we are copying an existing object into a new object
 * AOO is used when we are copying an existing object into an existing object 
 * 
 * Why do we need two different functions that do the same thing?:
 * Since AOO uses two exiting objects, we need a seperate function for it since the object being 
 * - copied onto may have existing dynamic memory.
 * if we copy over that exiting memory without deleting it first we might get a segfault, or 
 * - lose that memory on the heap creating a memory leak 
 * 
 * Remember we don't call these functions! check the main to see how they are called
 * Tip: use cout statements to see when they are called!
******************/

bookshelf::~bookshelf(){
    cout << "Destructor running!" << endl;
    delete [] books;
}

bookshelf::bookshelf(bookshelf &other_obj){
    cout << "Copy constructor running!" << endl;
    cout << "Copying " << other_obj.bookshelf_name << " to unnamed bookshelf" << endl;  
    //copy over all values from other obj 
    this->bookshelf_name = other_obj.bookshelf_name;
    this->num_books = other_obj.num_books;

    //creating memory and copying over all the memory from other_obj
    this->books = new string [this->num_books];
    for(int i = 0; i < this->num_books; i++){
        this->books[i] = other_obj.books[i];
    }
}

bookshelf& bookshelf::operator=(bookshelf &other_obj){
    cout << "Assignment operator overload running!" << endl; 
    cout << "Copying " << other_obj.bookshelf_name << " to " << this->bookshelf_name << endl;
    //check to see if they are pointing to the same obj -> good to make sure before you delete
    if(this != &other_obj){
        this->num_books = other_obj.num_books;
        this->bookshelf_name = other_obj.bookshelf_name;

        //before deleting, make sure the current books -> NULL
        if(this->books != NULL){
            delete [] this->books;
        }

        this->books = new string [this->num_books];
        for(int i = 0; i < this->num_books; i++){
            this->books[i] = other_obj.books[i];
        }
    }
    return *this; //returning b2
}
