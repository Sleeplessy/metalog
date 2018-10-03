//
// Created by Sleeplessy on 2018/10/2.
// 

// this is a very small program shows how this lib looks like

#include <iostream>
#include <vector>
#include "metalog/metalog.hpp"

class foo {};
class da : public foo {};
class zig {};

INVOKE_PRINTABLE(foo);
INVOKE_PRINTABLE(da);
INVOKE_PRINTABLE(int);


int main() {
  std::cout << std::boolalpha;
  std::cout << metalog::is_printable<foo>().type_name << " printable:" << metalog::is_printable<foo>::value << std::endl;
  std::cout << metalog::is_printable<da>().type_name << " printable:" <<metalog::is_printable<da>::value << std::endl;
  std::cout << metalog::content<int>().type_name<< " printable:" << metalog::is_printable<int>::value << std::endl;
  std::cout << metalog::is_printable<zig>().type_name << " printable:" << metalog::is_printable<zig>::value << std::endl;

  metalog::content<std::string> a("test");
  std::wcout << a << std::endl;
  std::cout << a << std::endl;
  return 0;
}