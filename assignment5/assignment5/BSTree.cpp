// Created by Jason Chu on 3/9/2022

#include "BSTree.h"

BSTree::BSTree() : root{nullptr} {}

// Delete all nodes in BST
BSTree::~BSTree(){
    clear(root);
}

// Insert new account
bool BSTree::insert(Account* account) {
    return recursiveInsert(account, root);
}

// Works as a helper function. Inserts a node recursively
bool BSTree::recursiveInsert(Account *Target, BSTree::Node *&RootPtr) {
    if (RootPtr == nullptr) {
        RootPtr = new Node(Target);
        RootPtr->account = Target;
        RootPtr->left = nullptr;
        RootPtr->right = nullptr;
        return true;
    } else {
        if (RootPtr->account->getID() > Target->getID()) {
            if (RootPtr->left == nullptr) {
                Node *Temp = new Node(Target);
                Temp->account = Target;
                Temp->left = nullptr;
                Temp->right = nullptr;
                RootPtr->left = Temp;
                return true;
            } else {
                return recursiveInsert(Target, RootPtr->left);
            }
        } else if (RootPtr->account->getID() < Target->getID()) {
            if (RootPtr->right == nullptr) {
                Node *Temp = new Node(Target);
                Temp->account = Target;
                Temp->left = nullptr;
                Temp->right = nullptr;
                RootPtr->right = Temp;
                return true;
            } else {
                return recursiveInsert(Target, RootPtr->right);
            }
        } else {
            return false;
        }
    }
}

// Retrieve account
// returns true if successful AND *account points to account
bool BSTree::retrieve(const int& accountNumber, Account*& account) const {
    account = recursiveRetrieve(root, accountNumber);
    return account != nullptr;
}

// Works as a helper function. Searches a node recursively
Account *BSTree::recursiveRetrieve(BSTree::Node *RootPtr, int Target) const {
    if (RootPtr == nullptr) {
        return nullptr;
    } else if (RootPtr->account->getID() == Target) {
        return RootPtr->account;
    } else if (Target < RootPtr->account->getID()) {
        return recursiveRetrieve(RootPtr->left, Target);
    } else {
        return recursiveRetrieve(RootPtr->right, Target);
    }
}

// Displays information on all accounts
void BSTree::display() const {
    display(root);
}

// Display information on all accounts
void BSTree::display(BSTree::Node *RootPtr) const {
    if (RootPtr != nullptr) {
        display(RootPtr->left);
        cout << RootPtr->account->getLastName() << " " <<
             RootPtr->account->getFirstName()
             << " Account ID: " << RootPtr->account->getID() << endl;

        for (int I = 0; I < 10; ++I) {
            cout << "       " << RootPtr->account->getFundName(I) << ": $" <<
                 RootPtr->account->getFundBalance(I) << endl;
        }
        cout << endl;
        display(RootPtr->right);
    }
}

// clear the entire BSTree
void BSTree::clear(Node *Node) {
    if (Node) {
        clear(Node->left);
        clear(Node->right);
        delete Node;
    }
}

// check if tree is empty
bool BSTree::isEmpty() const {
    return root == nullptr;
}