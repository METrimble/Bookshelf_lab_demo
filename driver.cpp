#include "bookshelf.h"

int main(){
    bookshelf b1;
    b1.create_bookshelf(3); //set values
    b1.print_bookshelf();

    //copy constructor
    bookshelf b2 = b1; //calls CC
    b2.print_bookshelf(); 

    //assignment operator
    bookshelf b3;
    b3.create_bookshelf(2); //set values
    b3.print_bookshelf(); //print the bookshelf

    b2 = b3; //calls AOO
    b2.print_bookshelf(); //print the bookshelf
}