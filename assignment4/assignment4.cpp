//
// Created by Jason Chu on 2/21/2022


#include <iostream>
#include <cassert>

#include "SkipList.h"

// testing skiplist of 1 level.
void test01() {
    SkipList s(1); 

    s.Add(35);
    s.Add(16); 
    s.Add(41); 
    s.Add(94); 
    s.Add(15);
    s.Add(87);
    s.Add(66);
    s.Add(60);

    cout << s << endl; 
    cout << "Test 1 complete" << endl;
    cout << endl;
}

// tests skiplist's Contains(), and Remove() functions.
void test02() {
    SkipList s(3);

    s.Add(35);
    s.Add(16); 
    s.Add(41); 
    s.Add(94); 
    s.Add(15);
    s.Add(87);
    s.Add(66);
    s.Add(60);
  
    cout << s << endl;    

    s.Remove(35);
  
    if (!s.Remove(35)) {
      cout << "35 has not been removed" << endl;
    } else {
      cout << "35 has been removed" << endl;
    }

    if (!s.Contains(35)) {
      cout << "35 is not in the skiplist." << endl;
    } else {
      cout << "35 is in the skiplist." << endl;
    }

    cout << s << endl;

    cout << "Test 2 complete" << endl;
}

// test provided by assignment guidelines
void test03() {
  SkipList s(5);

   for (int i = 0; i < 20; ++i) {
    int num = rand() % 100;
    s.Add(num);

    cout << "After adding" << num << endl;
    cout << s << endl;
  }
  cout << "Test 3 complete";
}

int main()
{
  cout << "-----------Starting test 1-----------" << endl;
  test01(); 

  cout << "-----------Starting test 2-----------" << endl;
  test02();

  cout << "-----------Starting test 3-----------" << endl;
  test03();
}