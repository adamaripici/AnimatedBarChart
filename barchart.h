// barchart.h
// TO DO: BarChart class
// Ada Pici
// UIC CS 251 FALL 2021

#include <algorithm>
#include <iostream>
#include <map>
#include "bar.h"
#include "myrandom.h"  // used in autograder, do not remove

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Codio (light/dark mode)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
  //
  // Private member variables for the abstraction.
  // This implementation uses a low-level C array, bars, to store a list of
  // Bars.  As a result, you must also keep track of the number of elements
  // stored (size) and the capacity of the array (capacity).  This is not a
  // dynamic array, so it does not expand.
  //
  Bar* bars;  // pointer to a C-style array
  int capacity;
  int size;
  string frame;

 public:
  // default constructor:
  BarChart() {
    // TO DO:  Write this constructor.
    bars = nullptr;
    capacity = 0;
    size = 0;
    frame = "";
  }

  // parameterized constructor:
  // Parameter passed in determines memory allocated for bars.
  BarChart(int n) {
    // TO DO:  Write this constructor.
    bars = new Bar[n];
    capacity = n;
    size = 0;
    frame = "";
  }

  //
  // copy constructor:
  //
  // Called automatically by C++ to create an BarChart that contains
  // a copy of an existing BarChart.  Example: this occurs when passing
  // BarChart as a parameter by value.
  //
  BarChart(const BarChart& other) {
    // TO DO:  Write this constructor.
    this->bars = new Bar[other.capacity];
    this->capacity = other.capacity;
    this->size = other.size;
    this->frame = other.frame;
    // copy the elements from the other array to this array
    for (int i = 0; i < other.size; i++) {
      this->bars[i] = other.bars[i];
    }
  }
  //
  // copy operator=
  //
  // Called when you assign one BarChart into another, i.e. this = other;
  //
  BarChart& operator=(const BarChart& other) {
    BarChart bc;

    // TO DO:  Write this operator.
    // special case : are we assigning to ourself?
    if (this == &other) {
      return *this;
    }

    //
    // unlike a copy constructor, *this* vector exists and so we first
    // have to free the memory associated with this vector:
    //
    delete[] bars;  // since we new'd an array, we delete[] an array

    // allocate this array with same capacity as the other:
    this->bars = new Bar[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;
    this->frame = other.frame;

    // now make a copy the elements from the other array into this one:
    for (int i = 0; i < other.size; i++) {
      this->bars[i] = other.bars[i];
    }

    // done, this array is now a copy of the other array:

    return *this;  // TO DO:  update this, it is only here so code compiles.
  }

  // clear
  // frees memory and resets all private member variables to default values.
  void clear() {
    // TO DO:  Write this operator.
    // to make sure elements are properly freed, let's free the array
    // and reallocate
    delete[] bars;

    bars = new Bar[0];
    size = 0;
    capacity = 0;
    frame = "";
  }

  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the
  // BarChart.
  //
  virtual ~BarChart() { delete[] bars; }

  // setFrame
  void setFrame(string frame) { this->frame = frame; }

  // getFrame()
  // Returns the frame of the BarChart oboject.
  string getFrame() {
    return frame;  // TO DO:  update this, it is only here so code compiles.
  }

  // addBar
  // adds a Bar to the BarChart.
  // returns true if successful
  // returns false if there is not room
  bool addBar(string name, int value, string category) {
    Bar bc(name, value, category);
    if (size ==
        capacity) {  // returns false if there it not enough room to add a Bar
      return false;
    } else {
      bars[size] = bc;
      size++;
    }
    return true;  // TO DO:  update this, it is only here so code compiles.
  }

  // getSize()
  // Returns the size (number of bars) of the BarChart object.
  int getSize() {
    return size;  // TO DO:  update this, it is only here so code compiles.
  }

  // testing capacity++REMOVE WHEN DONE
  int getCapacity() { return capacity; }

  // operator[]
  // Returns Bar element in BarChart.
  // This gives public access to Bars stored in the Barchart.
  // If i is out of bounds, throw an out_of_range error message:
  // "BarChart: i out of bounds"
  Bar& operator[](int i) {
    Bar b;
    // TO DO:  Write this function.
    if (i >= size || i < 0) {
      throw out_of_range("BarChart: i out of bounds");
    }
    return bars[i];  // TO DO:  update this, it is only here so code compiles.
  }

  // dump
  // Used for printing the BarChart object.
  // Recommended for debugging purposes.  output is any stream (cout,
  // file stream, or string stream).
  // Format:
  // "frame: 1
  // aname 5 category1
  // bname 4 category2
  // cname 3 category3" <-newline here
  void dump(ostream& output) {
    // sort in descending order
    sort(bars, bars + size, greater<Bar>());
    output << "frame: " << frame << endl;
    for (int i = 0; i < size; i++) {
      output << bars[i].getName() << " " << bars[i].getValue() << " "
             << bars[i].getCategory() << endl;
    }
  }

  // graph
  // Used for printing out the bar.
  // output is any stream (cout, file stream, string stream)
  // colorMap maps category -> color
  // top is number of bars you'd like plotted on each frame (top 10? top 12?)
  void graph(ostream& output, map<string, string>& colorMap, int top) {
    int lenMax = 60;  // this is number of BOXs that should be printed
    if (size == 0) {
      return;
    }
    int barsNumbers = 0;
    sort(bars, bars + size, greater<Bar>());
    string color = "";
    string barstr = "";
    int max = bars[0].getValue();
    for (int i = 0; i < top; i++) {  // The rest of the Bars
      barstr = "";
      barsNumbers = ((static_cast<double>(this->bars[i].getValue()) / max) *
                     lenMax);  // math to get the bars

      // get the color
      if (colorMap.empty() || colorMap.size() == 0 ||
          colorMap.count(bars[i].getCategory()) < 1) {
        color = BLACK;
      } else {
        color = colorMap.at(bars[i].getCategory());
      }

      for (int j = 0; j < barsNumbers; j++) {
        barstr += BOX;
      }
      output << color << barstr << ' ' << bars[i].getName() << ' '
             << bars[i].getValue() << endl;
    }
  }
};
