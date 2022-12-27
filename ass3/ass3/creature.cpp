//
// Created by Jason Chu on 10/29/2021
//
#include <iostream>

#include "creature.h"

// prints location of the creature
ostream &operator<<(ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.Row << Creature.Col << ")" << endl;
  return Out;
}

Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

// Checks if the creature is at the exit
bool Creature::atExit(const Maze &Maze) const {
  return (Row == Maze.getExitRow() && Col == Maze.getExitColumn());
}

// Creature will try to solve the given maze
string Creature::solve(Maze &Maze) {
  string Path;
  if (atExit(Maze))
    return "";
  Path = goEast(Maze);
  if (Path.empty()) {
    Path = goSouth(Maze);
    if (Path.empty()) {
      Path = goWest(Maze);
      if (Path.empty())
        Path = goNorth(Maze);
    }
  }
  return Path;
}

// Creature checks for clear path east
string Creature::goEast(Maze &Maze) {
  string Directions("E");

  if (Maze.isClear(Row, Col + 1)) {
    Maze.markAsPath(Row, ++Col);
    if (atExit(Maze))
      return "E";
    string E, S, N;
    if ((E = goEast(Maze)).empty()) {
      if ((S = goSouth(Maze)).empty()) {
        if ((N = goNorth(Maze)).empty()) {
          Directions.pop_back();
          Maze.markAsVisited(Row, Col--);
        } else
          Directions.append(N);
      } else
        Directions.append(S);
    } else
      Directions.append(E);
  } else
    Directions.pop_back();
  return Directions;
}

// Creature checks for clear path south
string Creature::goSouth(Maze &Maze) {
  string Directions("S");

  if (Maze.isClear(Row + 1, Col)) {
    Maze.markAsPath(++Row, Col);
    if (atExit(Maze))
      return "S";
    string S, W, E;
    if ((S = goSouth(Maze)).empty()) {
      if ((W = goWest(Maze)).empty()) {
        if ((E = goEast(Maze)).empty()) {
          Directions.pop_back();
          Maze.markAsVisited(Row--, Col);
        } else
          Directions.append(E);
      } else
        Directions.append(W);
    } else
      Directions.append(S);
  } else
    Directions.pop_back();
  return Directions;
}

// Creature checks for clear path west
string Creature::goWest(Maze &Maze) {
  string Directions("W");

  if (Maze.isClear(Row, Col - 1)) {
    Maze.markAsPath(Row, --Col);
    if (atExit(Maze))
      return "W";
    string W, N, S;
    if ((W = goWest(Maze)).empty()) {
      if ((N = goNorth(Maze)).empty()) {
        if ((S = goSouth(Maze)).empty()) {
          Directions.pop_back();
          Maze.markAsVisited(Row, Col++);
        } else
          Directions.append(S);
      } else
        Directions.append(N);
    } else
      Directions.append(W);
  } else
    Directions.pop_back();
  return Directions;
}

// Creature checks for clear path north
string Creature::goNorth(Maze &Maze) {
  string Directions("N");

  if (Maze.isClear(Row - 1, Col)) {
    Maze.markAsPath(--Row, Col);
    if (atExit(Maze))
      return "N";
    string N, E, W;
    if ((N = goNorth(Maze)).empty()) {
      if ((E = goEast(Maze)).empty()) {
        if ((W = goWest(Maze)).empty()) {
          Directions.pop_back();
          Maze.markAsVisited(Row++, Col);
        } else
          Directions.append(W);
      } else
        Directions.append(E);
    } else
      Directions.append(N);
  } else
    Directions.pop_back();
  return Directions;
}