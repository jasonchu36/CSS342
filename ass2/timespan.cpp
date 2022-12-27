//
// Created by Jason Chu on 10/14/2021.
//

#include "timespan.h"
#include<iomanip>

ostream &operator<<(ostream &out, const TimeSpan &ts) { 
  out << (ts.positive ? "" : "-");
  out << ts.hours << ":" << setw(2) << setfill('0') << ts.minutes;
  out << ":" << setw(2) << setfill('0') << ts.seconds;

  return out;
  }

//default constructor
TimeSpan::TimeSpan() {
  hours = 0;
  minutes = 0;
  seconds = 0;
}

//parameterized constructor
TimeSpan::TimeSpan(double hours) {
  this->hours = hours;
  minutes = 0;
  seconds = 0;
  positive = this->hours >=0;
  this->hours = abs(this->hours);
}

//parameterized constructor
TimeSpan::TimeSpan(double hours, double minutes) {
  this->minutes = minutes + hours * 60;

  positive = this->minutes >= 0;
  this->minutes = abs(this->minutes);

  this->hours = this->minutes / 60;
  this->minutes %= 60;
  seconds = 0;
}

//parameterized constructor
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
  this->seconds = hours * 3600 + minutes * 60 + seconds;
    
  positive = this->seconds >= 0;
  this->seconds = abs(this->seconds);

  this->minutes = this->seconds / 60;
  this->seconds %= 60;
  this->hours = this->minutes / 60;
  this->minutes %= 60;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
//TimeSpan::TimeSpan(double hour, double minute, double second) {}

// hour component
int TimeSpan::getHour() const { 
  return hours; 
}

// minute component
int TimeSpan::getMinute() const { 
  return minutes; 
}

// second component
int TimeSpan::getSecond() const { 
  return seconds; 
}

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { 
  return positive; 
}

// returns given time to only seconds
int TimeSpan::getInSeconds() const {
  return (hours * 3600 + minutes * 60 + seconds) * (positive ? 1 : -1);
}

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  //TimeSpan tsSum;
  //return tsSum;
  int sec;
  sec = getInSeconds() + ts.getInSeconds();

  TimeSpan result(0, 0, sec);

  return result;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  //TimeSpan tsSub;
  //return tsSub;
  int sec;
  sec =  getInSeconds() - ts.getInSeconds();

  TimeSpan result(0, 0, sec);

  return result;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  //TimeSpan tsLarge;
  //return tsLarge;
  return TimeSpan(0, 0, getInSeconds() * number);
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const { 
  return getInSeconds() == ts.getInSeconds(); 

}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const { 
  return !(*this == ts); 
}

// overload operator>
bool TimeSpan::operator>(TimeSpan const &ts) {
  return getInSeconds() > ts.getInSeconds();
}

//overload operator<
bool TimeSpan::operator<(TimeSpan const &ts) {
  return getInSeconds() < ts.getInSeconds();
}

//overload operator>=
bool TimeSpan::operator>=(TimeSpan const &ts)
{
  return (*this >= ts);
}

//overload operator<=
bool TimeSpan::operator<=(TimeSpan const &ts)
{
  return (*this <= ts);
}

//overload operator+=
TimeSpan& TimeSpan::operator+=(TimeSpan const &ts)
{
  int sec;
  sec = getInSeconds() + ts.getInSeconds();

  TimeSpan result(0, 0, sec);

  this->hours = result.hours;
  this->minutes = result.minutes;
  this->seconds = result.seconds;

  return *this;
}

// overload operator-=
TimeSpan& TimeSpan::operator-=(TimeSpan const &ts)
{
  int sec;
  sec =  getInSeconds() - ts.getInSeconds();

  TimeSpan result(0, 0, sec);

  this->hours = result.hours;
  this->minutes = result.minutes;
  this->seconds = result.seconds;

  return *this;
}