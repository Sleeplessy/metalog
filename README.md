# metalog

A meta-template style log system.

Currently only contains very basic features(really very basic). More updates would come these days.

## Usage

Put this repo in your include path, and include the main header in your source like:
```C++
#include <metalog/metalog.hpp>
```
or include the sparerate headers if you like:
```C++
#include <metalog/core/printable.hpp>
#include <metalog/core/content.hpp>
```

## Example
```C++
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
```


I do have plans for unit tests but not now, please went to the "main.cc" contains in the repo.

In my macOS using clang, the output of the example would be:
```
foo printable:true
da printable:true
i printable:true
3zig printable:false
test
test
[1, 2, 3]<1, 3, 4, 5>
```
