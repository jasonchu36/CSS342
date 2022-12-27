//
// Created by Jason Chu on 2/21/2022

#include <climits>
#include <cstdlib>
#include<iostream>

#include "SkipList.h"

using namespace std;

// output
ostream& operator<<(ostream& out, const SkipList& list) {
	SkipList::SNode* curr = nullptr;

	for (int i = list.depth - 1; i >= 0; i--) {
		curr = list.frontGuards[i];
		out << "Level: " << i << " -- " << curr->data;
		while (curr->next != nullptr) {
			out << ", " << curr->next->data;
			curr = curr->next;
		}
		out << " \n";
	}
	return out;
}

// SNode constructor initializing all points to nullptr
SkipList::SNode::SNode(int data) : data(data), next(nullptr), prev(nullptr), upLevel(nullptr), downLevel(nullptr) {}

// constructor
SkipList::SkipList(int depth) {
	this->depth = depth;
	this->frontGuards = new SNode * [depth];
	this->rearGuards = new SNode * [depth];
	
	for (int s = 0; s < depth; s++) {
		this->frontGuards[s] = new SNode(INT_MIN);
		this->rearGuards[s] = new SNode(INT_MAX);
		this->frontGuards[s]->next = this->rearGuards[s];
		this->rearGuards[s]->prev = this->frontGuards[s];
		if (s > 0) {
			this->frontGuards[s]->downLevel = this->frontGuards[s - 1];
			this->frontGuards[s - 1]->upLevel = this->frontGuards[s];
			this->rearGuards[s]->downLevel = this->rearGuards[s - 1];
			this->rearGuards[s - 1]->upLevel = this->rearGuards[s];
		}
	}

	this->frontGuards[0]->downLevel = nullptr;
	this->frontGuards[depth - 1]->upLevel = nullptr;
	this->rearGuards[0]->downLevel = nullptr;
	this->rearGuards[depth - 1]->upLevel = nullptr;
}

// destructor
SkipList::~SkipList() {
	SNode* curr;
	SNode* temp;

	for (int i = depth - 1; i >= 0; i--) {
		curr = frontGuards[i];
		while (curr != nullptr) {
			temp = curr;
			curr = curr->next;
			delete temp;
		}
		delete curr;
	}
	delete[] frontGuards;
	delete[] rearGuards;
}

// decides if data goes up one level 50% of the time
bool SkipList::alsoHigher() const {
	if ((rand() % 2) == 1) {
		return true;
	}
	return false;
}

// returns true if successfully added data with no duplicates
bool SkipList::Add(int data) {
	bool nextLevel = true;
	int i = 0;
	SNode* curr = frontGuards[0];

	while (data > curr->next->data) {
		curr = curr->next;

		if (data == curr->next->data) {
			return false;
		}
	}

	SNode* newNode = new SNode(data);
	addBefore(newNode, curr->next);

	do {
		i++;
		if (i == depth || !alsoHigher()) {
			nextLevel = false;
		}
		else {
			SNode* newUpper = new SNode(data);
			newUpper->downLevel = newNode;
			newNode->upLevel = newUpper;
			curr = frontGuards[i];

			while (data > curr->next->data) {
				curr = curr->next;
			}
			addBefore(newUpper, curr->next);
		}
	} while (nextLevel);
	return true;
}

// returns true if data was successfully removed
bool SkipList::Remove(int data) {
	SNode* curr = nullptr;
	SNode* temp = nullptr;
	
	for (int i = depth - 1; i >= 0; i--) {
		curr = frontGuards[i]->next;
		while (curr->next != nullptr && curr != frontGuards[i]) {
			if (curr->data == data) {
				while (curr != nullptr) {
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					temp = curr;
					curr = curr->downLevel;					
					delete temp;
					temp = nullptr;
				}
        return false;
			}
			curr = curr->next;
		}
	}
  return true;
}

// returns true if data is found in skiplist
bool SkipList::Contains(int data) const {
	SNode* curr = frontGuards[depth - 1];

	while (curr != nullptr) {
		if (curr->next->data == data) {
			return true;
		}
		while (curr->next->data < data) {
			curr = curr->next;
			if (curr->next->data == data) {
				return true;
			}
		}
		curr = curr->downLevel;
	}
	return false;
}

// rearranges pointers
void SkipList::addBefore(SNode* NewNode, SNode* NextNode) {
	NextNode->prev->next = NewNode;
	NewNode->prev = NextNode->prev;
	NewNode->next = NextNode;
	NextNode->prev = NewNode;
}