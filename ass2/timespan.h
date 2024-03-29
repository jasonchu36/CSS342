//
// Created by Yusuf Pisan on 4/2/18.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  int hours;
  int minutes;
  int seconds;
  bool positive;

  int getInSeconds() const;

  friend ostream &operator<<(ostream &out, const TimeSpan &ts);
  
public:
  TimeSpan();
  TimeSpan(double hours);
  TimeSpan(double hours, double minutes);
  TimeSpan(double hours, double minutes, double seconds);

  // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
  //explicit TimeSpan(double hour, double minute, double second);

  // add
  TimeSpan operator+(const TimeSpan &ts) const;

  // subtract
  TimeSpan operator-(const TimeSpan &ts) const;

  // check equality
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // multiply timespan by an unsigned number
  TimeSpan operator*(unsigned int number) const;

  // TODO(student)
  // to add operator+=, operator-=, operator<, operator>, operator<=, operator>=

  TimeSpan& operator+=(TimeSpan const &ts);
  TimeSpan& operator-=(TimeSpan const &ts);
  bool operator>(TimeSpan const &ts);
  bool operator<(TimeSpan const &ts);
  bool operator>=(TimeSpan const &ts);
  bool operator<=(TimeSpan const &ts);

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;

private:
};

#endif // ASS2_TIMESPAN_H