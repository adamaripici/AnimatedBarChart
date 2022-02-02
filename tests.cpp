// Ada Pici
// UIC CS 251 FALL 2021

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "barchartanimate.h"
using namespace std;

bool testBarDefaultConstructor() {
  Bar b;
  if (b.getName() != "") {
    cout << "testBarDefaultConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 0) {
    cout << "testBarDefaultConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "") {
    cout << "testBarDefaultConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBarDefaultConstructor2() {
  Bar b;
  if (b.getName() != "" && b.getValue() != 0) {
    cout << "testBarDefaultConstructor: getName failed" << endl;
    return false;
  } else if (b.getCategory() != "") {
    cout << "testBarDefaultConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarDefaultConstructor2: all passed!" << endl;
  return true;
}

bool testBarParamConstructor() {
  Bar b("Chicago", 9234324, "US");
  if (b.getName() != "Chicago") {
    cout << "testBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 9234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarParamConstructor: all passed!" << endl;
  return true;
}

bool testNegativeBarParamConstructor() {
  Bar b("Mexico City", -5000, "Mexico");
  if (b.getName() != "Mexico City") {
    cout << "testNegativeBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != -5000) {
    cout << "testNegativeBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "Mexico") {
    cout << "testNegativeBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testNegativeBarParamConstructor: all passed!" << endl;
  return true;
}

bool testLessThan() {
  Bar b("Mexico City", 2, "Mexico");
  Bar a("New York City", 5, "US");
  if (a < b) {
    cout << "testLessThan: < failed" << endl;
    return false;
  }

  cout << "testLessThan: all passed!" << endl;
  return true;
}

bool testGreaterThan() {
  Bar b("Mexico City", 600, "Mexico");
  Bar a("New York City", 100, "US");
  if (a > b) {
    cout << "testGreaterThan: < failed" << endl;
    return false;
  }

  cout << "testGreaterThan: all passed!" << endl;
  return true;
}

bool testLessThanTest2() {
  Bar b("Mexico City", 600, "Mexico");
  Bar a("New York City", 100, "US");
  if (a < b) {
    cout << "testLessThanTest2: all passed!" << endl;
    return true;
  } else {
    cout << "testLessThanTest2: < failed" << endl;
    return false;
  }
}

bool testGreaterThanOrEqualTo() {
  Bar b("Mexico City", 600, "Mexico");
  Bar a("New York City", 100, "US");
  Bar c("Chicago", 26, "US");
  if (b >= a && b > c) {
    cout << "testGreaterThanOrEqualTo: all passed!" << endl;
    return true;
  } else {
    cout << "testGreaterThanOrEqualTo: >= failed" << endl;
    return false;
  }
}

bool testLessThanOrEqualTo() {
  Bar b("Mexico City", 600, "Mexico");
  Bar a("New York City", 100, "US");
  Bar c("Chicago", 26, "US");
  if (a <= b && c < a) {
    cout << "testLessThanOrEqualTo: all passed!" << endl;
    return true;
  } else {
    cout << "testLessThanOrEqualTo: <= failed" << endl;
    return false;
  }
}

bool testBarChartDefaultConstructor() {
  BarChart bc;
  if (bc.getFrame() != "") {
    cout << "testBarChartDefaultConstructor: getCategory failed" << endl;
    return false;
  } else if (bc.getSize() != 0) {
    cout << "testBarChartDefaultConstructor: getSize failed" << endl;
    return false;
  }
  cout << "testBarChartDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBarChartParameterizedConstructor() {
  BarChart bc(10);
  if (bc.getCapacity() == 10 && bc.getFrame() == "" && bc.getSize() == 0) {
    cout << "testBarChartParameterizedConstructor: all passed!" << endl;
    return true;
  } else {
    cout << "testBarChartParameterizedConstructor: failed" << endl;
    return false;
  }
}

bool testCopyConstructor() {
  BarChart bc(10);
  BarChart bcCopy(bc);
  if (bc.getCapacity() == bcCopy.getCapacity()) {
    cout << "testCopyConstructor: all passed!" << endl;
    return true;
  } else {
    cout << "testCopyConstructor: failed" << endl;
    return false;
  }
}

bool testCopyConstructor2() {
  BarChart bc(60);
  BarChart bcCopy(bc);
  if (bc.getCapacity() != bcCopy.getCapacity()) {
    cout << "testCopyConstructor2: capacity failed" << endl;
    return false;
  } else if (bc.getSize() != bcCopy.getSize()) {
    cout << "testCopyConstructor2: size failed" << endl;
    return false;
  } else if (bc.getFrame() != bcCopy.getFrame()) {
    cout << "testCopyConstructor2: frame failed" << endl;
    return false;
  } else {
    cout << "testCopyConstructor2: all passed!" << endl;
    return true;
  }
}

bool testCopyOperator() {  // copy operator ==
  BarChart bc1;
  BarChart bc2(10);
  bc1 = bc2;
  if (bc1.getSize() != bc2.getSize()) {
    cout << "testCopyOperator: size failed" << endl;
    return false;
  } else if (bc1.getFrame() != bc2.getFrame()) {
    cout << "testCopyOperator: frame failed" << endl;
    return false;
  } else {
    cout << "testCopyOperator: all passed!" << endl;
    return true;
  }
}

bool testClear() {
  BarChart bc(10);
  bc.clear();
  if (bc.getSize() != 0) {
    cout << "testClear: failed" << endl;
    return false;
  } else if (bc.getFrame() != "") {
    cout << "testClear: failed" << endl;
    return false;
  } else if (bc.getCapacity() != 0) {
    cout << "testClear: failed" << endl;
    return false;
  } else {
    cout << "testClear: all passed!" << endl;
    return true;
  }
}

bool testSetFrame() {
  BarChart bc(3);
  bc.setFrame("1950");
  if (bc.getFrame() != "1950") {
    cout << "testSetFrame: failed" << endl;
    return false;
  } else {
    cout << "testSetFrame: all passed!" << endl;
    return true;
  }
}

bool testSetFrame2() {
  BarChart bc(1000);
  bc.setFrame("Los Angeles");
  if (bc.getFrame() != "Los Angeles") {
    cout << "testSetFrame2: failed" << endl;
    return false;
  } else {
    cout << "testSetFrame2: all passed!" << endl;
    return true;
  }
}

bool testAddBar() {
  BarChart bc(20);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("Seattle", 5939, "US");
  bc.addBar("Portland", 2121, "US");

  if (bc.getSize() != 3) {
    cout << "testAddBar: failed" << endl;
    return false;
  } else if (bc[0].getName() != "Chicago" && bc[1].getName() != "Seattle" &&
             bc[2].getName() != "Portland") {
    cout << "testAddBar: failed" << endl;
    return false;
  } else if (bc[0].getValue() != 1020 && bc[1].getValue() != 5939 &&
             bc[2].getValue() != 2121) {
    cout << "testAddBar: failed" << endl;
    return false;
  } else if (bc[0].getCategory() != "US" && bc[1].getCategory() != "US" &&
             bc[2].getCategory() != "US") {
    cout << "testAddBar: failed" << endl;
    return false;
  } else {
    cout << "testAddBar: all passed!" << endl;
    return true;
  }
}

bool testGetSize() {
  BarChart bc(20);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("Seattle", 5939, "US");
  bc.addBar("Portland", 2121, "US");
  bc.addBar("Michoacan", 2010, "Mexico");
  bc.addBar("Columbus", 2010, "US");

  int n = bc.getSize();
  if (n != 5) {
    cout << "testGetSize: failed" << endl;
    return false;
  } else {
    cout << "testGetSize: all passed!" << endl;
    return true;
  }
}

bool testBracketOperator() {
  BarChart bc(20);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("Seattle", 5939, "US");
  bc.addBar("Portland", 2121, "US");
  bc.addBar("Michoacan", 2010, "Mexico");
  bc.addBar("Columbus", 2010, "US");
  if (bc[0].getName() != "Chicago" && bc[1].getName() != "Seattle" &&
      bc[2].getName() != "Portland" && bc[3].getName() != "Michoacan" &&
      bc[4].getName() != "Columbus") {
    cout << "testBracketOperator: failed" << endl;
    return false;
  } else if (bc[0].getValue() != 1020 && bc[1].getValue() != 5939 &&
             bc[2].getValue() != 2121 && bc[3].getValue() != 2010 &&
             bc[4].getValue() != 2010) {
    cout << "testBracketOperator: failed" << endl;
    return false;
  } else if (bc[0].getCategory() != "US" && bc[1].getCategory() != "US" &&
             bc[2].getCategory() != "US" && bc[3].getCategory() != "Mexico" &&
             bc[4].getCategory() != "US") {
    cout << "testBracketOperator: failed" << endl;
    return false;
  } else {
    cout << "testBracketOperator: all passed!" << endl;
    return true;
  }
}

void testDump() {
  BarChart bc(20);
  bc.setFrame("1950");
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  stringstream ss("");
  bc.dump(ss);
  cout << ss.str();
}

void testEmptyDump() {
  BarChart bc;
  bc.dump(cout);
}

void testGraph() {
  BarChart bc(20);
  bc.setFrame("1950");
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  string red("\033[1;31m");
  string blue("\033[1;34m");
  map<string, string> colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  bc.graph(cout, colorMap, 3);
}

void testGraph2() {
  cout << "TestGraph2" << endl;
  BarChart bc(20);
  bc.setFrame("1930");
  bc.addBar("Portland", 1020, "US");
  bc.addBar("Seattle", 1400, "US");
  bc.addBar("Paris", 1000, "France");
  bc.addBar("Chicago", 2000, "US");
  bc.addBar("Mexico City", 1300, "Mexico");
  bc.addBar("Tokyo", 1100, "Japan");
  string red("\033[1;31m");
  string blue("\033[1;34m");
  string cyan("\033[1;36m");
  string white("\033[1;37m");
  map<string, string> colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  colorMap["Japan"] = cyan;
  colorMap["Mexico"] = white;
  bc.graph(cout, colorMap, 6);
}

bool testAddFrame() {
  string filename = "cities.txt";
  ifstream infile(filename);
  string title;
  string xlabel;
  string source;
  getline(infile, title, '\n');  // get the first line from file
  getline(infile, xlabel, '\n');
  getline(infile, source, '\n');

  BarChartAnimate bca(title, xlabel, source);  //
  while (!infile.eof()) {
    bca.addFrame(infile);  //
  }
  if (bca[0].getFrame() != "1500") {
    cout << "testAddFrame: failed" << endl;
    return false;
  } else if (bca[5].getFrame() != "1505") {
    cout << "testAddFrame: failed" << endl;
    return false;
  } else {
    cout << "testAddFrame: all passed" << endl;
    return true;
  }
}

void testNoColorsAllBlack() {
  cout << "No Colors" << endl;
  BarChart bc(20);
  bc.setFrame("1930");
  bc.addBar("Portland", 1020, "US");
  bc.addBar("Seattle", 1400, "US");
  map<string, string> colorMap;
  bc.graph(cout, colorMap, 2);
}

void testGraph3() {
  cout << "TestGraph3" << endl;
  BarChart bc(20);
  bc.setFrame("1930");
  bc.addBar("Beijing", 672, "East Asia");
  bc.addBar("Vijayanagar", 500, "South Asia");
  bc.addBar("Cauri", 400, "South Asia");
  bc.addBar("Chicago", 2000, "US");
  bc.addBar("Mexico City", 1300, "Latin America");
  map<string, string> colorMap;
  string red("\033[1;31m");
  string blue("\033[1;34m");
  string cyan("\033[1;36m");
  string white("\033[1;37m");
  colorMap["US"] = red;
  colorMap["East Asia"] = blue;
  colorMap["South Asia"] = cyan;
  colorMap["Latin America"] = white;
  bc.graph(cout, colorMap, 5);
}

void testEmpty() {
  cout << "Empty BarChart" << endl;
  BarChart bc;  // empty
  map<string, string> colorMap;
  bc.graph(cout, colorMap, 1);
}

bool testBarParamConstructor2() {
  Bar b("Chicago", 9234324, "US");
  if (b.getName() != "Chicago") {
    cout << "testBarParamConstructor: getName failed" << endl;
    return false;
  } else if (b.getValue() != 9234324) {
    cout << "testBarParamConstructor: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testBarParamConstructor: getCategory failed" << endl;
    return false;
  }
  cout << "testBarParamConstructor: all passed!" << endl;
  return true;
}

bool testBarChartGraph2() {
  BarChart bc(10);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  bc.setFrame("1950");
  string red("\033[1;36m");
  string blue("\033[1;33m");
  map<string, string> colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  stringstream result("");
  bc.graph(result, colorMap, 3);
  stringstream correct("");
  correct << red;
  for (int i = 0; i < 60; i++) {
    correct << BOX;
  }
  correct << " NYC 1300" << endl;
  correct << blue;
  for (int i = 0; i < (1200 * 60 / 1300); i++) {
    correct << BOX;
  }
  correct << " Paris 1200" << endl;
  correct << red;
  for (int i = 0; i < (1020 * 60 / 1300); i++) {
    correct << BOX;
  }
  correct << " Chicago 1020" << endl;
  cout << result.str() << endl;
  cout << correct.str() << endl;
  string R, C;
  R = result.str();
  C = correct.str();
  if (R.size() != C.size()) {
    cout << "strings diff in size (R=" << R.size() << ",C=" << C.size() << ")"
         << endl;
  }
  for (size_t i = 0; i < R.size() && i < C.size(); i++) {
    if (result.str()[i] != correct.str()[i]) {
      cout << "strings diff at index " << i << " (R=" << result.str()[i]
           << ",C=" << correct.str()[i] << ")" << endl;
    }
  }
  assert(R.size() == C.size());
  assert(R == C);
  cout << "testBarChart: all passed!" << endl;
  return true;
}

int main() {
  testBarDefaultConstructor();
  testBarDefaultConstructor2();
  testBarParamConstructor();
  testBarParamConstructor2();
  testNegativeBarParamConstructor();
  testLessThan();
  testGreaterThan();
  testLessThanTest2();
  testGreaterThanOrEqualTo();
  testLessThanOrEqualTo();
  testBarChartDefaultConstructor();
  testBarChartParameterizedConstructor();
  testCopyConstructor();
  testCopyConstructor2();
  testCopyOperator();
  testClear();
  testSetFrame();
  testSetFrame2();
  testAddBar();
  testGetSize();
  testBracketOperator();
  testDump();
  testGraph();
  testGraph2();
  testAddFrame();
  testNoColorsAllBlack();
  testGraph3();
  testEmpty();
  testEmptyDump();
  testBarChartGraph2();
  return 0;
}
