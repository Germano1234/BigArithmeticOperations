#include"expression-reader.hpp"
#include "big-integer-arithmetic.hpp"
#include <iostream>
using namespace std;

int main() {
  ExpressionReader er("test/expressions.txt");
  int line= 1; // had to do this so the output of main will be same as the expected output.

  while (!er.isEmpty()) {
    std::cout << er.processNextExpression() << "\n----------\n";
  }
  return 0;
}
