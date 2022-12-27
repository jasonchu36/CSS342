// Created by Jason Chu on 3/9/2022

#ifndef ASS5_BSTREE_H
#define ASS5_BSTREE_H

#include "account.h"
#include <iostream>

class BSTree {
  public:
    // Create BST
    BSTree();

    // Delete all nodes in BST
    ~BSTree();

    // Insert new account
    bool insert(Account* account);

    // Retrieve account
    // returns true if successful AND *Account points to account
    bool retrieve(const int& accountNumber, Account*& account) const;

    // Display information on all accounts
    void display() const;

    // delete all information in AccountTree
    void clear();

    // check if tree is empty
    bool isEmpty() const;

  private:
    class Node {
      public:
        //Node constructor
        explicit Node(Account* account)
            : account{account}, right{nullptr}, left{nullptr} {};
        ~Node() {
            delete account;
        }
        Account* account;
        Node* right;
        Node* left;
    };

    Node* root;

    // Works as a helper function. Searches a node recursively
    Account *recursiveRetrieve(Node *RootPtr, int Target) const;

    // Works as a helper function. Adds a node recursively
    bool recursiveInsert(Account *Target, Node *&RootPtr);

    // Works as a helper function. Displays information on all accounts recursively
    void display(Node *Root) const; // Helper function

    // delete all information in AccountTree
    void clear(Node *Node);
};
#endif //ASS5_BSTREE_H