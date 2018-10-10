//
// Created by Sleeplessy on 2018/10/2.
// 

// this is a very small program shows how this lib looks like

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "metalog/metalog.hpp"

class foo {};
class da : public foo {};
class zig {};

INVOKE_PRINTABLE(foo);
INVOKE_PRINTABLE(da);


int main() {
  std::cout << std::boolalpha;
  std::cout << metalog::is_printable<foo>().type_name << " printable:" << metalog::is_printable<foo>::value << std::endl;
  std::cout << metalog::is_printable<da>().type_name << " printable:" <<metalog::is_printable<da>::value << std::endl;
  std::cout << metalog::content<int>().type_name<< " printable:" << metalog::is_printable<int>::value << std::endl;
  std::cout << metalog::is_printable<zig>().type_name << " printable:" << metalog::is_printable<zig>::value << std::endl;
//
//  metalog::content<std::string> a("test");
//  std::wcout << a << std::endl;
//  std::cout << a << std::endl;
  metalog::content<std::vector<int>> v({1,2,3});
  metalog::content<std::list<long>,wchar_t > l({1,3,4,5});

  metalog::content<std::list<std::string>> s({"123","测试","世界は酷て辛いことだった"});
  v.bracket_value = v.square;
  l.bracket_value = l.pointy;
  s.bracket_value = s.brace;

  std::vector<std::wstring> zz{L"123",L"测试测试测试",L"JOJO"};


  std::cout << v;
  std::cout << s;
  return 0;
}