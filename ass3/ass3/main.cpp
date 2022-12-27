#include <iostream>

#include "creature.h"
#include "maze.h"

void test() {
  Maze M("maze.txt");
  Creature C(4, 4);
  cout << "Path: " << C.solve(M) << endl;
  cout << M << endl;
}

void test1() {
  Maze M("maze1.txt");
  Creature C(5, 9);
  cout << "Path: " << C.solve(M) << endl;
  cout << M << endl;
}

void test2() {
  Maze M("maze2.txt");
  Creature C(5, 9);
  cout << "Path: " << C.solve(M) << endl;
  cout << M << endl;
}

void test3() {
  Maze M("maze3.txt");
  Creature C(5, 9);
  cout << "Path: " << C.solve(M) << endl;
  cout << M << endl;
}

int main() {
  test();
  test1();
  test2();
  test3();
  cout << "Done!" << std::endl;
  return 0;
}