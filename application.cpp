// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//
// Ada Pici
// UIC CS 251 FALL 2021
// Creative Component Instructions:
// To run: ./application.exe
// program will ask you to enter a filename from a list of
// of filenames. Once you enter the filename the program will ask you
// for a playback speed. A playback speed of 1 is equal to very fast and
// the higher the number input is the slower the graph will be.

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include "barchartanimate.h"
using namespace std;

// calculate what the top integer should be based on filename input
void calculateTop(string filename, int& top) {
  if (filename == "baby-names.txt") {
    top = 10;
  } else if (filename == "cities.txt") {
    top = 12;
  } else if (filename == "countries.txt") {
    top = 30;
  } else if (filename == "brands.txt") {
    top = 75;
  } else if (filename == "cities-usa.txt") {
    top = 31;
  } else if (filename == "endgame.txt") {
    top = 57;
  } else if (filename == "football.txt") {
    top = 25;
  } else if (filename == "game-of-thrones.txt") {
    top = 3;
  } else if (filename == "infinity-war.txt") {
    top = 37;
  } else {
    cout << "error" << endl;
  }
}

int main() {
  string filename;
  int top;
  cout << "Available filenames: baby-names.txt"
       << " cities.txt "
       << "countries.txt brands.txt cities-usa.txt endgame.txt"
       << " football.txt game-of-thrones.txt infinity-war.txt" << endl;

  cout << "Enter Filename: ";
  cin >> filename;
  ifstream inFile(filename);
  if (!inFile.is_open()) {  // wrong filename
    cout << "Error: unable to open '" << filename << "'";
    return 0;
  }
  int speed;
  cout << "Enter playback speed: (1 for fastest): ";
  cin >> speed;
  string title;
  getline(inFile, title);
  string xlabel;
  getline(inFile, xlabel);
  string source;
  getline(inFile, source);

  BarChartAnimate bca(title, xlabel, source);

  while (!inFile.eof()) {
    bca.addFrame(inFile);
  }

  calculateTop(filename, top);
  bca.animate(cout, top, 10, speed);  // animate graph

  return 0;
}
