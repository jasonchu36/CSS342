//
// Created by Jason Chu on 10/10/2021.
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {
  

public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();
  
  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // list all books
  bool listAllBooks() const;

  // true if book found in library
  bool isInLibrary(const string &BookName) const;
  
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);

private:
  static const int MAX = 100;
  string books[MAX];
  int numberOfBooks;
  string LibraryName;
};

#endif  // ASS1_LIBRARY_H
