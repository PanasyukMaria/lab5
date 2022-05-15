#include <iostream>
#include "Stack.hpp"

int main() {
  std::cout << "All system is online!";
  Stack<int> Mystck;
  Mystck.push(1);
  Mystck.push(14);
  std::cout << Mystck.head();
}