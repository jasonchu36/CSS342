// 
// Created by Jason Chu on 2/21/2022

#ifndef ASS4_SKIPLIST_H
#define ASS4_SKIPLIST_H

#include <iostream>

using namespace std;

class SkipList {
    friend ostream& operator<<(ostream& out, const SkipList& list);

private:
    class SNode {
    public:
        // SNode sotres int as data
        explicit SNode(int data);

        // data for SNode
        int data;

        // link to next SNode
        SNode* next;

        // link to previous SNode
        SNode* prev;

        // link to up one level
        SNode* upLevel;

        // link to down one level
        SNode* downLevel;
    };

    // depth of SkipList
    int depth;

    // array of depth SNode* objects as frontGuards linking levels
    // if depth = 2, we'd have frontGuards[0] and frontGuards[1]
    SNode** frontGuards;

    // aaray of depth SNode* objects as rearGuards linking levels
    SNode** rearGuards;

    // given a SNode, place it before the given nextNode
    void addBefore(SNode* newNode, SNode* nextNode);

    // return true 50% of the time,
    // each node has a 50% chance of being at higher level
    bool alsoHigher() const;

public:
    // default SkipList has depth of 1, just one doubly-linked list 
    explicit SkipList(int depth = 1);

    // destructor
    virtual ~SkipList();

    // return true if successfully add,no duplicates
    bool Add(int data);

    // return true if successfully removed
    bool Remove(int data);

    // returns true if found in SkipList
    bool Contains(int data) const;
};

#endif // ASS4_SKIPLIST_H