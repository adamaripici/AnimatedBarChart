// bar.h
// TO DO: Bar class. Aggregates related information (name, value, and category)
// Ada Pici
// UIC CS 251 FALL 2021

#include <iostream>
#include <string>
#include "myrandom.h"  // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
  // Private member variables for a Bar object
  // TO DO:  Define private member variables for this class
  // NOTE: You should not be allocating memory on the heap for this class.
  string name;
  int value;
  string category;

 public:
  // default constructor:
  Bar() {
    // TO DO:  Write this constructor.
    name = "";
    value = 0;
    category = "";
  }

  //
  // a second constructor:
  //
  // Parameter passed in constructor Bar object.
  //
  Bar(string name, int value, string category) {
    // TO DO:  Write this constructor.
    this->name = name;
    this->value = value;
    this->category = category;
  }

  // destructor:
  virtual ~Bar() {
    // TO DO:  Write this destructor or leave empty if not needed.
  }

  // getName: Return the name
  string getName() { return name; }

  // getValue:
  int getValue() {
    return value;  // TO DO:  update this, it is only here so code compiles.
  }

  // getCategory: Return the category
  string getCategory() { return category; }

  // operators
  // TO DO:  Write these operators.  This allows you to compare two Bar
  // objects.  Comparison should be based on the Bar's value.  For example:
  bool operator<(const Bar &other) const {
    if (this->value < other.value) {
      return true;
    } else {
      return false;
    }
  }

  // Less than or equal to operator
  bool operator<=(const Bar &other) const {
    if (this->value <= other.value) {
      return true;
    } else {
      return false;
    }
  }

  // less than operator
  bool operator>(const Bar &other) const {
    if (this->value > other.value) {
      return true;
    } else {
      return false;
    }
  }

  // greater than or equal to operator
  bool operator>=(const Bar &other) const {
    if (this->value >= other.value) {
      return true;
    } else {
      return false;
    }
  }
};
