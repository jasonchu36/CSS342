//
// Created by Jason Chu on 10/10/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) {
  LibraryName = Name;
  numberOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  if (numberOfBooks == 0) return false;
  for (int i = 0; i < numberOfBooks; i++) {
    if (BookName.compare(books[i]) == 0) {
      return true;
    }
  }
  return false;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  if (numberOfBooks < MAX) {
    books[numberOfBooks++] = BookName;
    for (int i = 0; i < numberOfBooks; i++){
      if (books[i] == books[i+1]){
        return false;
      }
    }
  } 
  return true;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  if (numberOfBooks == 0) return false;
  for(int i = 0; i < numberOfBooks; i++) {
    if (BookName == books[i]) {
    books[i] = books[numberOfBooks--];
    numberOfBooks--;
    return true;
    }
  }
  return false;
}

// list all books
bool Library::listAllBooks() const {
  if (numberOfBooks == 0) return false;
  cout << "Library Name: " << LibraryName << endl;
  cout << "Library Book List:\n";
  for (int i = 0; i < numberOfBooks; i++) cout << books[i] << endl;
  return true;
}

ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << Lib.listAllBooks();
  return Out;
}